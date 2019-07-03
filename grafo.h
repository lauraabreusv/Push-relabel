#ifndef GRAFO_H
#define GRAFO_H

typedef struct Vertice Vertice;
typedef struct Celula Celula;

struct Celula{
	float fluxo;
	float capacidade;
	int id_vertice;
	Celula *prox;
};

struct Vertice{
	int altura;
	float excesso;
	Celula *arestas;
};

void InsereLista(Vertice *grafo, int v1, int v2, float c, float f);

#endif
