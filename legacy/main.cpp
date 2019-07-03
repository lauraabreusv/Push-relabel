#include "grafo.hpp"
#include "ff.hpp"
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int v1, v2, peso;
	if(n > 0){
		Graph *grafo = new Graph();
		for(int i = 0; i < n; i++){
			Vertice v(i); 
			grafo->vertices.push_back(v);
		}
		for(int i = 0; i < m; i++){
			cin>>v1>>v2>>peso;
			Cell vertice2(v2, peso);
			Cell vertice1(v1, peso);
			grafo->vertices[v1].adjacencias.push_back(vertice2);
			grafo->vertices[v2].adjacencias.push_back(vertice1);
		}
		vector<int> caminhos;
		int fluxo_max = 10000000;
		vector<int> caminhos_final;
		int retorno;
		for(int i = 1; i < n; i++){
			retorno = fordFulkerson(grafo, 0, i, &caminhos);
			if(retorno < fluxo_max) {
				fluxo_max = retorno;
				caminhos_final = caminhos;
			}
			zera_fluxos(grafo);
			caminhos.clear();
			for(int i = 0; i < n; i++){
				grafo->vertices[i].set_visitado(false);
			}
		}
		cout<<caminhos_final.size()<<endl;
		for(int i = 0; i < caminhos_final.size(); i++){
			cout<<caminhos_final[i]<<" ";
		}
		cout<<endl;
		cout<<fluxo_max<<endl;

		delete grafo;
	}
}