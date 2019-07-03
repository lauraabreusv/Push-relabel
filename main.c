#include "grafo.h"
#include "push-relabel.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	int n, m;//numero de vertices e arestas
	int s, t;//source e sink
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);
	Vertice* grafo_residual = (Vertice*)malloc(n*sizeof(Vertice));//criacao residual
	for(int i = 0; i < n; i++){
		grafo_residual[i].arestas = NULL;
		grafo_residual[i].altura = 0;
		grafo_residual[i].excesso = 0;
	}
	int v1, v2, c;//vertices que tem aresta v1 -> v2 com capacidade c
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &v1, &v2, &c);
		InsereLista(grafo_residual, v1, v2, c, 0);
		InsereLista(grafo_residual, v2, v1, c, c);//a aresta reversa sempre tera o fluxo "c-fluxo" -> no inicio eh c
	}

	PreFluxo(grafo_residual, s, n);//iniciou o pre-fluxo ok
	int vertice_atual = VerticesComExcesso(grafo_residual, n, t, s);
	// int count = 0;
	while(vertice_atual != -1){
		printf("%d\n", vertice_atual);
		if(!Push(grafo_residual, vertice_atual)){
			Relabel(grafo_residual, vertice_atual);
			printf("altura nova eh: %d\n", grafo_residual[vertice_atual].altura);
		}
		for(int i = 0; i < n; i++){
			printf("Vertice %d com fluxos: ", i);
			Celula *aux = grafo_residual[i].arestas;
			while(aux != NULL){
				printf("%d ", aux->fluxo);
				aux = aux->prox;
			}
			printf("\n");
		}
		printf("e o excesso novo do vertice eh: %d\n", grafo_residual[vertice_atual].excesso);
		// if(count == 12) break;
		// count++;
		vertice_atual = VerticesComExcesso(grafo_residual, n, t, s);
	}
	printf("O fluxo maximo eh %d\n", grafo_residual[t].excesso);

	return 0;
}
//testa os fluxos nos grafos
	// for(int i = 0; i < n; i++){
	// 	printf("Vertice %d com fluxos: ", i);
	// 	Celula *aux = grafo_residual[i].arestas;
	// 	while(aux != NULL){
	// 		printf("%d ", aux->fluxo);
	// 		aux = aux->prox;
	// 	}
	// 	printf("\n");
	// }