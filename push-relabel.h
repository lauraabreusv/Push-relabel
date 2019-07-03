#include "grafo.h"

void PreFluxo(Vertice *grafo, int s, int n);
void Relabel(Vertice *grafo_residual, int v);
int min(int a, int b);
void AtualizaFluxoReverso(Vertice *grafo_residual, int v_atual, int v_alvo, float fluxo);
int Push(Vertice *grafo_residual, int v);
int VerticesComExcesso(Vertice *grafo_residual, int n, int t, int s);