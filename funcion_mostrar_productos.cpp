<<<<<<< HEAD
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
=======

// para reutilizar al momento que se encuentra el producto y mostrarlo en este formato 
// por que no se como hacer para ponerle en una sola funcion 
>>>>>>> 5332ce2f078b1cfcbcf3147e1c19204633971de3

void mostrar(const Producto& prod) {
    cout << "ID: " << prod.id << endl;
    cout << "Nombre: " << prod.nombre << endl;
    cout << "CategorÃ­a: " << prod.categoria << endl;
    cout << "Precio: " << prod.precio << endl;
    cout << "---------------------------\n";
}
