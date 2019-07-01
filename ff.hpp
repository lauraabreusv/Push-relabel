#ifndef FF_H
#define FF_H

int min(int a, int b);
bool DFS(Graph *grafo, int current, int target, int *aumento, vector<int> *caminhos);
int fordFulkerson(Graph *grafo, int f, int s, vector<int> *caminhos);
void DFS_corte_min(Graph *grafo, int current, vector<int> *caminhos);
void zera_fluxos(Graph *grafo);
#endif

