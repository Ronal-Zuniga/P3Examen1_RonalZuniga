#include "HTHPlus.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

HTHPlus::HTHPlus() {
}

HTHPlus::~HTHPlus() {
	for(int i = 0; i < this->peliculas.size(); i++) {
		Pelicula* p = this->peliculas[i];
		delete p;
		this->peliculas.erase(peliculas.begin()+i);
	}
}

void HTHPlus::addPelicula(Pelicula* peli) {
	this->peliculas.push_back(peli);
}

void HTHPlus::modTitulo(int posicion, string _titulo) {
	this->peliculas[posicion]->setTitulo(_titulo);
}

void HTHPlus::modDirector(int posicion, string _director) {
	this->peliculas[posicion]->setDirector(_director);
}

void HTHPlus::modGenero(int posicion, string _genero) {
	this->peliculas[posicion]->setGenero(_genero);
}

void HTHPlus::modValoracion(int posicion) {
	this->peliculas[posicion]->setValoracion();
}

void HTHPlus::deletePelicula(int posicion) {
	Pelicula* p = this->peliculas[posicion];
	delete p;
	this->peliculas.erase(peliculas.begin()+posicion);
}

void HTHPlus::imprimir() {
	cout << endl;
	cout << "Peliculas guardadas" << endl;
	cout << endl;
	for(int i = 0; i < this->peliculas.size(); i++) {
		cout << i << ". " << this->peliculas[i]->toString() << endl;
	}
	cout << endl;
}