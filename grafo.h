#ifndef GRAFO_H
#define GRAFO_H

typedef struct Vertice Vertice;
typedef struct Celula Celula;

struct Celula{
	int fluxo;
	int capacidade;
	int id_vertice;
	Celula *prox;
};

struct Vertice{
	int altura;
	int excesso;
	Celula *arestas;
};

void InsereLista(Vertice *grafo, int v1, int v2, int c);

#endif