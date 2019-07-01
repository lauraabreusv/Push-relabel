#include "grafo.hpp"
#include <vector>
#include <iostream>
#include <iterator>

void zera_fluxos(Graph *grafo){
	for(int i = 0; i < grafo->vertices.size(); i++){
		list<Cell>::iterator it;
		for(it = grafo->vertices[i].adjacencias.begin(); it != grafo->vertices[i].adjacencias.end(); it++){
			it->set_fluxo(0);
		}
	}
}

void DFS_corte_min(Graph *grafo, int current, vector<int> *caminhos){
	if(grafo->vertices[current].get_visitado() == true){
		return;
	}
	else{
		list<Cell>::iterator it = grafo->vertices[current].adjacencias.begin();
		grafo->vertices[current].set_visitado(true);
		caminhos->push_back(grafo->vertices[current].get_indice());
		for(it = grafo->vertices[current].adjacencias.begin(); it != grafo->vertices[current].adjacencias.end(); it++){
			if(it->get_fluxo() < it->get_peso() && it->get_fluxo() >= 0){
		 		DFS_corte_min(grafo, it->get_i(), caminhos);
			}
		}
		for(it = grafo->vertices[current].adjacencias.begin(); it != grafo->vertices[current].adjacencias.end(); it++){
			if(it->get_fluxo() < 0){
		 		DFS_corte_min(grafo, it->get_i(), caminhos);
			}
		}
		return;
	}
}

int min(int a, int b){
	if(a < b) return a;
	else return b;
}

bool DFS(Graph *grafo, int current, int target, int *aumento, vector<int> *caminhos){
	if(grafo->vertices[current].get_indice() == target){
		caminhos->push_back(grafo->vertices[current].get_indice());
		return true; 
	}
	else if(grafo->vertices[current].get_visitado() == true){
		return false;
	}
	else{
		list<Cell>::iterator it = grafo->vertices[current].adjacencias.begin();
		grafo->vertices[current].set_visitado(true);
		bool found = false;
		for(it = grafo->vertices[current].adjacencias.begin(); it != grafo->vertices[current].adjacencias.end(); it++){
			if(found == true){
				break;
			}
			else if(it->get_fluxo() < it->get_peso() && it->get_fluxo() >= 0){
				*aumento = min(*aumento, (it->get_peso() - it->get_fluxo()));
		 		found = DFS(grafo, it->get_i(), target, aumento, caminhos);
			}
		}
		for(it = grafo->vertices[current].adjacencias.begin(); it != grafo->vertices[current].adjacencias.end(); it++){
			if(found == true) {
				break;
			}
			else if(it->get_fluxo() < 0){
				*aumento = min(*aumento, ((-1)*it->get_fluxo()));
		 		found = DFS(grafo, it->get_i(), target, aumento, caminhos);
			}
		}
		if(found){
			caminhos->push_back(grafo->vertices[current].get_indice());
		}
		return found;
	}
}

int fordFulkerson(Graph *grafo, int f, int s, vector<int> *caminhos){
	list<Cell>::iterator it;
	int aux = 0;
	int aumento = 10000000;
	while(DFS(grafo, f, s, &aumento, caminhos)){
		for(int i = caminhos->size()-1; i > 0; i--){
			for(it = grafo->vertices[(*caminhos)[i]].adjacencias.begin(); it != grafo->vertices[(*caminhos)[i]].adjacencias.end(); it++){
				if(it->get_i() == (*caminhos)[i-1]) {
					aux = it->get_fluxo() + aumento;
					it->set_fluxo(aux);
					break;
				}
			}
			for(it = grafo->vertices[(*caminhos)[i-1]].adjacencias.begin(); it != grafo->vertices[(*caminhos)[i-1]].adjacencias.end(); it++){
				if(it->get_i() == (*caminhos)[i]) {
					it->set_fluxo((-1)*aux);
					break;
				}
			}
		}
		for(int i = 0; i < grafo->vertices.size(); i++){
			grafo->vertices[i].set_visitado(false);
		}
		caminhos->clear();
		aumento = 10000000; 
	}
	for(int i = 0; i < grafo->vertices.size(); i++){
		grafo->vertices[i].set_visitado(false);
	}
	caminhos->clear();
	int fluxo_maximo = 0;
	for(it = grafo->vertices[s].adjacencias.begin(); it !=  grafo->vertices[s].adjacencias.end(); it++){
		fluxo_maximo += (-1)*it->get_fluxo();
	}
	DFS_corte_min(grafo, f, caminhos); 
	return fluxo_maximo;
}
