void mostrarProductos() {
	cout << "------LISTA DE PRODUCTOS----- \n";
    ifstream archivo("productos.txt");
    string linea;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}


// para reutilizar al momento que se encuentra el producto y mostrarlo en este formato 
// por que no se como hacer para ponerle en una sola funcion 

void mostrar(const Producto& prod) {
    cout << "ID: " << prod.id
	     << " | Nombre: " << prod.nombre
             << " | Categoría: " << prod.categoria 
	     << " | Precio: $" << prod.precio << endl;
}
