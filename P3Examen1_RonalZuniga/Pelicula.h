#ifndef PELICULA
#define PELICULA
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Pelicula{
	private:
		string titulo;
		string director;
		string genero;
		int valoracion;
	
	public:
		Pelicula();
		Pelicula(string, string, string);
		string getTitulo();
		void setTitulo(string);
		string getDirector();
		void setDirector(string);
		string getGenero();
		void setGenero(string);
		int getValoracion();
		void setValoracion();
		string toString();
};

#endif