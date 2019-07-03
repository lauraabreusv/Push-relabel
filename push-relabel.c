#include "grafo.h"
#include "push-relabel.h"
#include <stdio.h>
#include <stdlib.h>

void AtualizaFluxoReverso(Vertice *grafo_residual, int v_atual, int v_alvo, float fluxo){
	Celula *aux = grafo_residual[v_atual].arestas;
	while(aux != NULL){
		if(aux->id_vertice == v_alvo){
			aux->fluxo -= fluxo;
			return;
		}
		aux = aux->prox;
	}
}

int min(int a, int b){
	if(a < b) return a;
	else return b;
}

void PreFluxo(Vertice *grafo_residual, int s, int n){
	grafo_residual[s].altura = n;//inicia com o source tendo altura igual ao numero de vertices do grafo
	Celula *aux = grafo_residual[s].arestas;
	while(aux != NULL){
		aux->fluxo = aux->capacidade;
		grafo_residual[aux->id_vertice].excesso = aux->capacidade;
		AtualizaFluxoReverso(grafo_residual, aux->id_vertice, s, aux->fluxo);
		aux = aux->prox;
	}
}

void Relabel(Vertice *grafo_residual, int v){
	int min = 1000000;
	Celula *aux = grafo_residual[v].arestas;
	while(aux != NULL){
		if(min > grafo_residual[aux->id_vertice].altura && aux->capacidade - aux->fluxo > 0){
			min = grafo_residual[aux->id_vertice].altura;
			grafo_residual[v].altura = min + 1;
		}
		aux = aux->prox;
	}
}

int Push(Vertice *grafo_residual, int v){
	Celula *aux = grafo_residual[v].arestas;
	while(aux != NULL){
		if(aux->capacidade - aux->fluxo > 0 && grafo_residual[v].altura > grafo_residual[aux->id_vertice].altura){
			int fluxo = min(grafo_residual[v].excesso, aux->capacidade - aux->fluxo);
			grafo_residual[v].excesso -= fluxo;
			grafo_residual[aux->id_vertice].excesso += fluxo; //um push sempre cria excesso no outro
			aux->fluxo += fluxo;//aumenta o fluxo naquela aresta
			AtualizaFluxoReverso(grafo_residual, aux->id_vertice, v, fluxo);
			return 1;
		}
		aux = aux->prox;
	}
	return 0;	
}

int VerticesComExcesso(Vertice *grafo_residual, int n, int t, int s){
	for(int i = 0; i < n; i++){
		if(grafo_residual[i].excesso > 0 && i != t && i != s){
			return i;
		}
	}
	return -1;
}

