#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Producto {
	int id;
	string nombre;
	string categoria;
	double precio;
};

bool buscarProductoPorID(int idBuscar, Producto& prodEncontrado, const string& nombreArchivo = "productos.txt") {
	ifstream archivo(nombreArchivo);
	Producto prod;
	
	while (archivo >> prod.id) {
		archivo.ignore();
		getline(archivo, prod.nombre, ',');
		getline(archivo, prod.categoria, ',');
		archivo >> prod.precio;
		archivo.ignore();
		
		if (prod.id == idBuscar) {
			prodEncontrado = prod;
			return true;
		}
	}
	
	return false;
}
