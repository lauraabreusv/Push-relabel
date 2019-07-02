#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

void InsereLista(Vertice *grafo, int v1, int v2, int c){
	Celula *nova = (Celula*)malloc(sizeof(Celula));
	nova->prox = NULL;
	nova->capacidade = c;
	nova->fluxo = 0;
	nova->id_vertice = v2;
	if(grafo[v1].arestas == NULL){
		grafo[v1].arestas = nova;
	}
	else{
		Celula *aux = grafo[v1].arestas;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = nova;
	}
}