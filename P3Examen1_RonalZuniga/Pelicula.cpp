#include "Pelicula.h"
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

Pelicula::Pelicula(){
}

Pelicula::Pelicula(string _titulo, string _director, string _genero){
	this->titulo = _titulo;
	this->director = _director;
	this->genero = _genero;
	setValoracion();
}

string Pelicula::getTitulo(){
	return this->titulo;
}

void Pelicula::setTitulo(string _titulo){
	this->titulo = _titulo;
}

string Pelicula::getDirector(){
	return this->director;
}

void Pelicula::setDirector(string _director){
	this->director = _director;
}

string Pelicula::getGenero(){
	return this->genero;
}

void Pelicula::setGenero(string _genero){
	this->genero = _genero;
}

int Pelicula::getValoracion(){
	return this->valoracion;
}

void Pelicula::setValoracion(){
	srand ((unsigned)time(0));
	this->valoracion = 1 + (rand() % (5));
}

string Pelicula::toString(){
	return this->titulo + " - " + this->director + " - " 
	+ this->genero + " - " + to_string(this->valoracion) + "/5";
}

