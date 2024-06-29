#include <iostream>
#include <string>

using namespace std;

const int NUM_ESTANTES = 4;
const int NUM_PRODUCTOS = 6;
const int STOCK_MINIMO = 10;
const int MAX_PRODUCTOS_SISTEMA = 10; 

struct Producto {
    string nombre;
    int cantidad;
};

struct ProductoSistema {
    string nombre;
    int cantidad;
};

Producto estantes[NUM_ESTANTES][NUM_PRODUCTOS] = {
    {{"Leche Entera 1L", 50}, {"Leche Deslactosada 1L", 30}, {"Leche Descremada 1L", 20},
     {"Leche Entera 1.5L", 40}, {"Leche Deslactosada 1.5L", 25}, {"Leche Descremada 1.5L", 15}},
    {{"Leche Entera 2L", 60}, {"Leche Deslactosada 2L", 35}, {"Leche Descremada 2L", 25},
     {"Leche Entera 250ml", 80}, {"Leche Fresa 250ml", 50}, {"Leche Vainilla 250ml", 40}},
    {{"Leche Chocolate 250ml", 30}, {"Leche Chocomenta 250ml", 20}, {"Leche Cookies and Cream 250ml", 15},
     {"Leche Entera 250ml", 90}, {"Leche Fresa 250ml", 60}, {"Leche Vainilla 250ml", 50}},
    {{"Leche Fresa 180ml", 40}, {"Leche Vainilla 180ml", 30}, {"Leche Capuchino 180ml", 20},
     {"Leche Chocolate 180ml", 40}, {"Leche Chocomenta 180ml", 30}, {"Leche Cookies and Cream 180ml", 20}}
};

ProductoSistema productosSistema[MAX_PRODUCTOS_SISTEMA];
int numProductosSistema = 0;

void mostrarEstantes() {
    cout << "Estantes:\n";
    for (int i = 0; i < NUM_ESTANTES; i++) {
        cout << "Estante " << i + 1 << ":\n";
        for (int j = 0; j < NUM_PRODUCTOS; j++) {
            cout << "  - " << estantes[i][j].nombre << " (Cantidad: " << estantes[i][j].cantidad << ")\n";
        }
    }
    
    cout << "\nProductos nuevos del sistema:\n";
    for (int i = 0; i < numProductosSistema; i++) {
        cout << "  - " << productosSistema[i].nombre << " (Cantidad: " << productosSistema[i].cantidad << ")\n";
    }
}

void venderProducto(int estante, int producto, int cantidad) {
    if (estantes[estante - 1][producto - 1].cantidad >= cantidad) {
        estantes[estante - 1][producto - 1].cantidad -= cantidad;
        cout << "Venta realizada con éxito.\n";
    } else {
        cout << "No hay suficiente stock para realizar la venta.\n";
    }
}

void actualizarProducto(int estante, int producto, string nuevoNombre, int nuevaCantidad) {
    estantes[estante - 1][producto - 1].nombre = nuevoNombre;
    estantes[estante - 1][producto - 1].cantidad = nuevaCantidad;
    cout << "Información del producto actualizada con éxito.\n";
}

void reabastecerInventario(int estante, int producto, int cantidad) {
    estantes[estante - 1][producto - 1].cantidad += cantidad;
    cout << "Inventario reabastecido con éxito.\n";
}

void agregarProductoSistema(string nombre, int cantidad) {
    if (numProductosSistema < MAX_PRODUCTOS_SISTEMA) {
        productosSistema[numProductosSistema].nombre = nombre;
        productosSistema[numProductosSistema].cantidad = cantidad;
        numProductosSistema++;
        cout << "Producto agregado al sistema.\n";
    } else {
        cout << "No se pueden agregar más productos al sistema.\n";
    }
}

int main() {
    string usuario;
    string contrasena;
    bool autenticado = false;

    while (!autenticado) {
        cout << "Ingrese usuario: ";
        cin >> usuario;
        cout << "Ingrese contraseña: ";
        cin >> contrasena;

        if ((usuario == "JEDRECK" || usuario == "ELIZABETH" || usuario == "ALEXANDRA" || usuario == "MAURICIO") &&
            contrasena == "deli77") {
            autenticado = true;
        } else {
            cout << "Credenciales incorrectas. Intente de nuevo.\n";
        }
    }

    cout << "\nBIENVENIDO A DELI LECHE!\n";

    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "\nSeleccione una opción:\n";
        cout << "1. Mostrar estantes\n";
        cout << "2. Vender producto\n";
        cout << "3. Actualizar información de producto\n";
        cout << "4. Reabastecer inventario\n";
        cout << "5. Agregar producto al sistema\n";
        cout << "6. Salir\n";

        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarEstantes();
                break;
            case 2: {
                int estante, producto, cantidad;
                cout << "Ingrese el número de estante (1-" << NUM_ESTANTES << "): ";
                cin >> estante;
                cout << "Ingrese el número de producto (1-" << NUM_PRODUCTOS << "): ";
                cin >> producto;
                cout << "Ingrese la cantidad a vender: ";
                cin >> cantidad;
                venderProducto(estante, producto, cantidad);
                break;
            }
            case 3: {
                int estante, producto, nuevaCantidad;
                string nuevoNombre;
                cout << "Ingrese el número de estante (1-" << NUM_ESTANTES << "): ";
                cin >> estante;
                cout << "Ingrese el número de producto (1-" << NUM_PRODUCTOS << "): ";
                cin >> producto;
                cout << "Ingrese el nuevo nombre del producto: ";
                cin.ignore(); 
                getline(cin, nuevoNombre);
                cout << "Ingrese la nueva cantidad del producto: ";
                cin >> nuevaCantidad;
                actualizarProducto(estante, producto, nuevoNombre, nuevaCantidad);
                break;
            }
            case 4: {
                int estante, producto, cantidad;
                cout << "Ingrese el número de estante (1-" << NUM_ESTANTES << "): ";
                cin >> estante;
                cout << "Ingrese el número de producto (1-" << NUM_PRODUCTOS << "): ";
                cin >> producto;
                cout << "Ingrese la cantidad a reabastecer: ";
                cin >> cantidad;
                reabastecerInventario(estante, producto, cantidad);
                break;
            }
            case 5: {
                string nombreNuevoProducto;
                int cantidadNuevoProducto;
                cout << "Ingrese el nombre del nuevo producto para el sistema: ";
                cin.ignore(); 
                getline(cin, nombreNuevoProducto);
                cout << "Ingrese la cantidad inicial del producto: ";
                cin >> cantidadNuevoProducto;
                agregarProductoSistema(nombreNuevoProducto, cantidadNuevoProducto);
                break;
            }
            case 6:
                salir = true;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    }

    cout << "\nGracias por utilizar DELI LECHE!\n";
    return 0;
}