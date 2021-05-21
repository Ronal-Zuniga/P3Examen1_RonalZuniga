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
	this->peliculas.clear();
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

void HTHPlus::imprimirGenero() {
	//1. asignar los generos sin repeticiones a un vector
	vector<string> generos;
	string aux = "";
	for(int i = 0; i < this->peliculas.size(); i++) {
		aux = this->peliculas[i]->getGenero();
		if(generos.empty()) {
			generos.push_back(aux);
		} else {
			bool contiene = false;
			for(int j = 0; j < generos.size(); j++) {
				if(aux == generos[j]) {
					contiene = true;
					break;
				} else {
					contiene = false;
				}
			}
			if(!contiene) {
				generos.push_back(aux);
			}
		}
	}

	//2. imprimir las peliculas segun el vector de generos
	for(int i = 0; i < generos.size(); i++) {
		cout << generos[i] << ":" << endl;
		for(int j = 0; j < this->peliculas.size(); j++) {
			if(this->peliculas[j]->getGenero() == generos[i]) {
				cout << "	 " << this->peliculas[j]->toString() << endl;
			}
		}
	}
}//fin metodo imprimir por genero

void HTHPlus::buscarPelicula(string busqueda) {
	cout << endl;
	cout << "Resultados de la busqueda (" << busqueda << "): " << endl;
	for(int j = 0; j < this->peliculas.size(); j++) {
		if(this->peliculas[j]->getTitulo().find(busqueda) != string::npos) {
			cout << "	 " << this->peliculas[j]->toString() << endl;
		}
	}
	cout << endl;
}//fin metodo buscar

void HTHPlus::imprimirValoracion(){
	//ordena todos los miembros del vector peliculas segun su valoracion
	for(int i = 0; i < this->peliculas.size(); i++){
		for(int j = i+1; j < this->peliculas.size(); j++){
			if(this->peliculas[i]->getValoracion() < this->peliculas[j]->getValoracion()){
				Pelicula* temp = this->peliculas[j];
				this->peliculas[j] = this->peliculas[i];
				this->peliculas[i] = temp;
			}
		}
	}
	//una vez las peliculas estan ordenadas, imprime de manera normal
	cout << endl;
	cout << "Peliculas ordenadas segun su valoracion" << endl;
	cout << endl;
	for(int i = 0; i < this->peliculas.size(); i++) {
		cout << i << ". " << this->peliculas[i]->toString() << endl;
	}
	cout << endl;
}//fin metodo ordenar valoracion