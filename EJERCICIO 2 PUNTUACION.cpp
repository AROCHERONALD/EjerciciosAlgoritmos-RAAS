#include <iostream>
#include <vector>

using namespace std;

int calcularPuntaje(const vector<int>& numeros) {
    int puntaje = 0;
    
    for (size_t i = 0; i < numeros.size(); ++i) {
        int valor = numeros[i];
        
        if (valor == 5) {
            puntaje += 5; 
        } else if (valor % 2 == 0) {
            puntaje += 1; 
        } else {
            puntaje += 3; 
        }
    }
    
    return puntaje;
}

int main() {
    int cantidad;

    cout << "Ingrese la cantidad de elementos en la MATRIZ: ";
    cin >> cantidad;

    vector<int> numeros(cantidad);
    
    cout << "Introduzca los valores de la MATRIZ: "; //Observacion Ing. Entre cada valor ingresado solo va espacio Ejemplo: 17 19 21 = 9
    for (int i = 0; i < cantidad; ++i) {
        cin >> numeros[i];
    }

    cout << "El puntaje total calculado es: " << calcularPuntaje(numeros) << endl;

    return 0;
}

