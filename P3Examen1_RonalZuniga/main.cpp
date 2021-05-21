#include <iostream>
#include "Pelicula.h"
#include "HTHPlus.h"
#include <string>
using namespace std;
int menu();
void agregarPelicula(HTHPlus*);
int submenu();

int main() {
	int opcion = 0;
	HTHPlus* televisora = new HTHPlus();
	while((opcion = menu()) != 8) {
		switch(opcion) {
			case 1: {
				agregarPelicula(televisora);
				break;
			}

			case 2: {
				int opcionMod = 0;
				while((opcionMod = submenu()) != 5) {
					switch(opcionMod) {
						case 1: {
							int indice = 0;
							string _titulo;
							televisora->imprimir();
							cout << "Ingrese el indice de la pelicula a modificar: ";
							cin >> indice;
							cin.ignore();
							cout << "Ingrese el nuevo titulo de la pelicula: ";
							getline(cin, _titulo);
							televisora->modTitulo(indice, _titulo);
							cout << "El titulo se modifico correctamente" << endl;
							cout << endl;
							break;
						}

						case 2: {
							int indice = 0;
							string _director;
							televisora->imprimir();
							cout << "Ingrese el indice de la pelicula a modificar: ";
							cin >> indice;
							cin.ignore();
							cout << "Ingrese el nuevo director de la pelicula: ";
							getline(cin, _director);
							televisora->modDirector(indice, _director);
							cout << "El director se modifico correctamente" << endl;
							cout << endl;
							break;
						}

						case 3: {
							int indice = 0;
							string _genero;
							televisora->imprimir();
							cout << "Ingrese el indice de la pelicula a modificar: ";
							cin >> indice;
							cin.ignore();
							cout << "Ingrese el nuevo genero de la pelicula: ";
							getline(cin, _genero);
							televisora->modGenero(indice, _genero);
							cout << "El titulo se modifico correctamente" << endl;
							cout << endl;
							break;
						}

						case 4: {
							int indice = 0;
							televisora->imprimir();
							cout << "Ingrese el indice de la pelicula a modificar: ";
							cin >> indice;
							cout << "Generando nueva valoracion aleatoria" << endl;
							televisora->modValoracion(indice);
							cout << "La valoracion se modifico correctamente" << endl;
							cout << endl;
							break;
						}
					}//fin switch submenu
				}//fin while submenu
				break;
			}

			case 3: {
				int indice = 0;
				televisora->imprimir();
				cout << "Ingrese el indice de la pelicula a eliminar: ";
				cin >> indice;
				televisora->deletePelicula(indice);
				cout << "La pelicula se ha eliminado correctamente" << endl;
				break;
			}

			case 4: {
				televisora->imprimir();
				break;
			}

			case 5: {
				cout << endl;
				cout << "Lista de Peliculas segun su Genero" << endl;
				cout << endl;
				televisora->imprimirGenero();
				cout << endl;
				break;
			}

			case 6: {
				string busqueda;
				cout << "Ingrese una cadena para buscar en los titulos: ";
				getline(cin, busqueda);
				televisora->buscarPelicula(busqueda);
				break;
			}

			case 7: {
				televisora->imprimirValoracion();
				break;
			}
		}//fin del switch
	}//fin del while
	televisora->~HTHPlus();
	delete televisora;
	return 0;
}

int menu() {
	int opcion = 0;
	cout << "----MENU----" << endl;
	cout << "1. Agregar Pelicula" << endl;
	cout << "2. Modificar Pelicula" << endl;
	cout << "3. Eliminar Pelicula" << endl;
	cout << "4. Listar Peliculas" << endl;
	cout << "5. Imprimir Peliculas por Genero" << endl;
	cout << "6. Buscar Pelicula" << endl;
	cout << "7. Imprimir Peliculas por Valoracion" << endl;
	cout << "8. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	cin.ignore();
	cout << endl;
	while(opcion <= 0 || opcion > 8) {
		cout << "Seleccione una opcion dentro del rango" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cin.ignore();
		cout << endl;
	}
	return opcion;
}

void agregarPelicula(HTHPlus* televisora) {
	string titulo;
	string director;
	string genero;
	cout << "Ingrese el titulo de la pelicula: ";
	getline(cin, titulo);
	cout << "Ingrese el director de la pelicula: ";
	getline(cin, director);
	cout << "Ingrese el genero de la pelicula: ";
	getline(cin, genero);
	televisora->addPelicula(new Pelicula(titulo, director, genero));
	cout << endl;
	cout << "La pelicula se agrego correctamente" << endl;
	cout << endl;
}

int submenu() {
	int opcion = 0;
	cout << "----Menu de Modificar Pelicula----" << endl;
	cout << "1. Modificar Titulo" << endl;
	cout << "2. Modificar Director" << endl;
	cout << "3. Modificar Genero" << endl;
	cout << "4. Modificar Valoracion" << endl;
	cout << "5. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	cin.ignore();
	cout << endl;
	while(opcion <= 0 || opcion > 5) {
		cout << "Seleccione una opcion dentro del rango" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cin.ignore();
		cout << endl;
	}
	return opcion;
}