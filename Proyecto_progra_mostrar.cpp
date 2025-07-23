//NO ESTA YA NO VALE :( 

void mostrarProductos() {
	cout << "------LISTA DE PRODUCTOS----- \n";
    ifstream archivo("productos.txt");
    string linea;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}
