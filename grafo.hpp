#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Cell{
	private:
		int i; // indice do vertice
		int peso; 
		int fluxo;
	public:
		Cell(int indice, int p);
		int get_i();
		int get_peso();
		int get_fluxo();
		void set_fluxo(int f);
};

class Vertice{
	private:
		int indice;
		bool visitado;
	public:
		Vertice(int i);
		list<Cell> adjacencias;

		int get_indice();
		bool get_visitado();

		void set_visitado(bool v);
};

class Graph{
	public:
		vector<Vertice> vertices;
};

#endif