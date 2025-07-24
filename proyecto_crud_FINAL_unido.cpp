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


vector<Producto> leerProductosDesdeArchivo(const string& nombreArchivo = "productos.txt") {
	ifstream archivoEntrada(nombreArchivo);
	vector<Producto> productos;
	Producto prod;
	
	while (archivoEntrada >> prod.id) {
		archivoEntrada.ignore();
		getline(archivoEntrada, prod.nombre, ',');
		getline(archivoEntrada, prod.categoria, ',');
		archivoEntrada >> prod.precio;
		archivoEntrada.ignore();
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

// Menú principal
int main() {
	setlocale(LC_ALL, "spanish");
	int opcion;
	do {
		cout << "1. Crear orden de trabajo" << endl;
		cout << "2. Mostrar ordenes de trabajo" << endl;
		cout << "3. Actualizar orden de trabajo" << endl;
		cout << "4. Eliminar orden de trabajo" << endl;
		cout << "5. Buscar orden" << endl;
		cout << "6. Salir" << endl;
		cout << "Elige una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
			case 1: {
				Producto prod;
				cout << "IMEI: "; cin >> prod.id;
				cin.ignore();
				cout << "CLIENTE: "; getline(cin, prod.nombre);
				cout << "REPARACION: "; getline(cin, prod.categoria);
				cout << "VALOR R.: "; cin >> prod.precio;
				agregarProductoAlArchivo(prod);
				cout << "=====ORDEN AGREGADA EXITOSAMENTE=====.\n";
				break;
			}
			case 2: {
				auto productos = leerProductosDesdeArchivo();
				mostrarProductos(productos);
				break;
			}
			case 3: {
				int id;
				cout << "IMEI a actualizar: "; cin >> id;
				cin.ignore();
				
				Producto nuevo;
				nuevo.id = id;
				cout << "Nuevo CLIENTE: "; getline(cin, nuevo.nombre);
				cout << "Nueva REPARACION: "; getline(cin, nuevo.categoria);
				cout << "Nuevo PRECIO R. "; cin >> nuevo.precio;
				
				auto productos = leerProductosDesdeArchivo();
				if (actualizarProductoPorID(productos, id, nuevo)) {
					guardarProductosEnArchivo("productos.txt", productos);
					cout << "=====ORDEN ACTUALIZADA EXITOSAMENTE=====\n";
				} else {
					cout << "IMEI DE ORDEN NO ENCONTRADA.\n";
				}
				break;
			}
			case 4: {
				int id;
				cout << "IMEI a eliminar: "; cin >> id;
				auto productos = leerProductosDesdeArchivo();
				if (eliminarProductoPorID(productos, id)) {
					guardarProductosEnArchivo("productos.txt", productos);
					cout << "=====EQUIPO ELIMINADO EXITOSAMENTE=====\n";
				} else {
					cout << "ORDEN NO ENCONTRADA.\n";
				}
				break;
			}
			case 5: {
				int id;
				cout << "IMEI de orden a buscar: "; cin >> id;
				Producto encontrado;
				if (buscarProductoPorID(id, encontrado)) {
					mostrar(encontrado);
				} else {
					cout << "ORDEN NO ENCONTRADA..\n";
				}
				break;
			}
		case 6:
			cout << "Saliendo del programa ONLY SMART TECH...\n";
			break;
		default:
			cout << "Opcion invalida escoja una opcion de 1 al 6.\n";
		}
		
	} while (opcion != 6);
	
	return 0;
}

