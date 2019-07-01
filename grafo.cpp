#include "grafo.hpp"

using namespace std;

Cell::Cell(int indice, int p){
	this->i = indice;
	this->peso = p;
	this->fluxo = 0;
}

int Cell::get_i(){
	return this->i;
}


int Cell::get_peso(){
	return this->peso;
}

int Cell::get_fluxo(){
	return this->fluxo;
}

void Cell::set_fluxo(int f){
	this->fluxo = f;
}

Vertice::Vertice(int i){
	this->indice = i;
}

int Vertice::get_indice(){
	return this->indice;
}

bool Vertice::get_visitado(){
	return this->visitado;
}

void Vertice::set_visitado(bool v){
	this->visitado = v;
}