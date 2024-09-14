#include <iostream>
#include <string>
using namespace std;

// Definición de una estructura para un Producto
struct Producto {
    int codigo;
    string nombre;
    int cantidad;
};

// Definir un tamaño máximo para el inventario
const int MAX_PRODUCTOS = 100;
Producto inventario[MAX_PRODUCTOS];
int totalProductos = 0;

// Función para agregar un producto al inventario
void agregarProducto() {
    if (totalProductos <= MAX_PRODUCTOS) {  
        Producto nuevoProducto;
        cout << "Ingrese el código del producto: ";
        cin >> nuevoProducto.codigo;
        cin.ignore();  // Limpiar el buffer antes de leer cadenas
        cout << "Ingrese el nombre del producto: ";
        getline(cin, nuevoProducto.nombre); // getline(cin, nuevoProducto.nombre);  
        cout << "Ingrese la cantidad del producto: ";
        cin >> nuevoProducto.cantidad;
        
        inventario[totalProductos] = nuevoProducto;
        totalProductos += 1; // totalProductos += 1;  
        
        cout << "Producto agregado exitosamente.\n";
        cout << "Total de productos: " << totalProductos << endl; // cout << "Total de productos: " << totalProductos << endl;  
    } else {
        cout << "El inventario está lleno.\n";
    }
}

// Función para mostrar todos los productos del inventario
void mostrarProductos() {
    if (totalProductos == 0) {
        cout << "No hay productos en el inventario.\n";
    } else {
        cout << "Inventario de productos:\n";
        for (int i = 0; i <= totalProductos; i++) {  
            cout << "Código: " << inventario[i].codigo
                 << " | Nombre: " << inventario[i].nombre
                 << " | Cantidad: " << inventario[i].cantidad << endl;
        }
    }
}

// Función para actualizar la cantidad de un producto
void actualizarProducto() {
    int codigo;
    cout << "Ingrese el código del producto a actualizar: ";
    cin >> codigo;
    
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            cout << "Ingrese la nueva cantidad: ";
            cin >> inventario[i].cantidad;
           cout << "Producto Actualizado "; // Falta mensaje de confirmación aquí
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Función para eliminar un producto del inventario
void eliminarProducto() {
    int codigo;
    cout << "Ingrese el código del producto a eliminar: ";
    cin >> codigo;
    
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            for (int j = i; j < totalProductos; j++) {  // Error: debe ser j < totalProductos - 1
                inventario[j] = inventario[j + 1];
            }
            totalProductos --;  // totalProductos --;  
            cout << "Producto Eliminado de Inventario ";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Función principal con menú
int main() {
    int opcion;
    do {
        cout << "\n--- Sistema de Gestión de Inventario ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Actualizar cantidad de producto\n";
        cout << "4. Eliminar producto\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        // cin.ignore();  
        
        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                actualizarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 5);
    
    return 0;
}
