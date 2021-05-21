#ifndef HTHPLUS
#define HTHPLUS
#include "Pelicula.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HTHPlus {
	private:
		vector<Pelicula*> peliculas;
	
	public:
		HTHPlus();
		~HTHPlus();
		void addPelicula(Pelicula*);
		void modTitulo(int, string);
		void modDirector(int, string);
		void modGenero(int, string);
		void modValoracion(int);
		void deletePelicula(int);
		void imprimir();
		void imprimirGenero();
		void imprimirValoracion();
		void buscarPelicula(string);
};

#endif