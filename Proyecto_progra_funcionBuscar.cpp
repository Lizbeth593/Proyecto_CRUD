void buscarProducto() {
    ifstream archivo("productos.txt");
    int idBuscar;
    bool encontrado = false;
    Producto prod;

    cout << "Ingresa el ID del producto que deseas buscar: ";
    cin >> idBuscar;
