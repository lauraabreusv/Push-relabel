#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

void InsereLista(Vertice *grafo, int v1, int v2, float c, float f){
	Celula *nova = (Celula*)malloc(sizeof(Celula));
	nova->prox = grafo[v1].arestas;
	nova->capacidade = c;
	nova->fluxo = f;
	nova->id_vertice = v2;
	grafo[v1].arestas = nova;
}
