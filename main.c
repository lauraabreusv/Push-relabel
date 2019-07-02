#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	int n, m;//numero de vertices e arestas
	int s, t;//source e sink
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);
	Vertice* grafo = (Vertice*)malloc(n*sizeof(Vertice));//criacao do grafo
	for(int i = 0; i < n; i++){
		grafo[i].arestas = NULL;//precisa disso?
	}
	int v1, v2, c;//vertices que tem aresta v1 -> v2 com capacidade c
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &v1, &v2, &c);
		InsereLista(grafo, v1, v2, c);
	}
	
	//so pra ver se ta dando bom
	for(int i = 0; i < n; i++){
		printf("Vertice %d ", i);
		printf("com lista: ");
		Celula *aux = grafo[i].arestas;
		while(aux != NULL){
			printf("%d ", aux->id_vertice);
			aux = aux->prox;
		}
		printf("\n");
	}

	return 0;
}