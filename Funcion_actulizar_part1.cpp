void actualizarProducto() {
	ifstream archivoEntrada("productos.txt");
	ofstream archivoSalida("temp.txt");
	
	int idBuscado;
	bool encontrado = false;
	Producto prod;
	
	cout << "Ingresa el ID del producto que deseas actualizar: ";
	cin >> idBuscado;
	
	while (archivoEntrada >> prod.id) {
		archivoEntrada.ignore();
		getline(archivoEntrada, prod.nombre, ',');
		getline(archivoEntrada, prod.categoria, ',');
		archivoEntrada >> prod.precio;
