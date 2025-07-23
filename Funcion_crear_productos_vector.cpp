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


bool idExiste(int idBuscado, const string& nombreArchivo) {
	ifstream archivo(nombreArchivo);
	if (!archivo.is_open()) return false;
	
	string linea;
	while (getline(archivo, linea)) {
		stringstream text(linea);
		string idStr;
		getline(text, idStr, ','); 
		
		if (stoi(idStr) == idBuscado) {
			return true;  
		}
	}
	return false;  
}

void agregarProductoAlArchivo(const Producto& prod, const string& nombreArchivo = "productos.txt") {
	if (idExiste(prod.id, nombreArchivo)) {
		cout << "La orden con IMEI " << prod.id << " ya existe. No se puede agregar.\n";
		return;
	}
	
	ofstream archivo(nombreArchivo, ios::app);
	if (archivo.is_open()) {
		archivo << prod.id << ","
		<< prod.nombre << ","
		<< prod.categoria << ","
		<< prod.precio << endl;
		archivo.close();
		cout << "Orden agregado exitosamente.\n";
	} else {
		cout << "No se pudo abrir el archivo.\n";
	}
}

