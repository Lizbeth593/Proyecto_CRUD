#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Producto {
    int id;
    string nombre;
    string categoria;
    double precio;
};

void crearProducto() {
    ofstream archivo("productos.txt", ios::app);
    Producto prod;

    cout << "ID del producto: ";
    cin >> prod.id;
    cin.ignore();  

    cout << "Nombre del producto: ";
    getline(cin, prod.nombre);
    
    cout << "Categoría: ";
    getline(cin, prod.categoria);
    
    cout << "Precio (USD): ";
    cin >> prod.precio;

    archivo << prod.id << "," << prod.nombre << "," << prod.categoria << "," << prod.precio << endl;
    archivo.close();
}
