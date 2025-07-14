void eliminarProducto() {
	ifstream archivoEntrada("productos.txt");
	ofstream archivoSalida("temp.txt");
	
	int idEliminar;
	bool encontrado = false;
	Producto prod;
	
	cout << "Ingresa el ID del producto que deseas eliminar: ";
	cin >> idEliminar;
}
