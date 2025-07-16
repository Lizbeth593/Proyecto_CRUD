void mostrarProductos() {
    cout << "------LISTA DE PRODUCTOS----- \n";
    ifstream archivo("productos.txt");
    Producto prod;

    while (archivo >> prod.id) {
        archivo.ignore(); 
        getline(archivo, prod.nombre, ',');
        getline(archivo, prod.categoria, ',');
        archivo >> prod.precio;
        archivo.ignore(); 

        cout << "ID: " << prod.id << endl;
        cout << "Nombre: " << prod.nombre << endl;
        cout << "Categoría: " << prod.categoria << endl;
        cout << "Precio: " << prod.precio << endl;
        cout << "---------------------------\n";
    }

    archivo.close();
}
