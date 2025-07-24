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

void mostrar(const Producto& prod) {
	cout << "IMEI: " << prod.id << endl;
	cout << "CLIENTE: " << prod.nombre << endl;
	cout << "REPARACION: " << prod.categoria << endl;
	cout << "VALOR R.: " << prod.precio << endl;
	cout << "---------------------------\n";
}

void mostrarProductos(const vector<Producto>& productos) {
	cout << "------LISTA DE EQUIPOS------\n";
	for (const auto& prod : productos) {
		mostrar(prod);
	}
}
