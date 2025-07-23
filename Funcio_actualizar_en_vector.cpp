#include <iostream>
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

vector<Producto> leerProductosDesdeArchivo(const string& nombreArchivo) {
	ifstream archivoEntrada(nombreArchivo);
	vector<Producto> productos;
	Producto prod;
	
	while (archivoEntrada >> prod.id) {
		archivoEntrada.ignore();
		getline(archivoEntrada, prod.nombre, ',');
		getline(archivoEntrada, prod.categoria, ',');
		archivoEntrada >> prod.precio;
		productos.push_back(prod);
	}
	
	archivoEntrada.close();
	return productos;
}

void guardarProductosEnArchivo(const string& nombreArchivo, const vector<Producto>& productos) {
	ofstream archivoSalida(nombreArchivo);
	
	for (const auto& p : productos) {
		archivoSalida 
		<< p.id << ","
		<< p.nombre << ","
		<< p.categoria << ","
		<< p.precio << endl;
	}
	
	archivoSalida.close();
}

bool actualizarProductoPorID(vector<Producto>& productos, int idBuscado, const Producto& nuevosDatos) {
	for (auto& prod : productos) {
		if (prod.id == idBuscado) {
			prod.nombre = nuevosDatos.nombre;
			prod.categoria = nuevosDatos.categoria;
			prod.precio = nuevosDatos.precio;
			return true; 
		}
	}
	return false; 
}

