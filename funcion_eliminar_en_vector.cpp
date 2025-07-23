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

bool eliminarProductoPorID(vector<Producto>& productos, int idEliminar) {
	size_t tamAntes = productos.size();
	
	productos.erase(
		remove_if(productos.begin(), productos.end(),
			[idEliminar](const Producto& prod) {
				return prod.id == idEliminar;
			}),
		productos.end());
	
	return productos.size() < tamAntes;
}
