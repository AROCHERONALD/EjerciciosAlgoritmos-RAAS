#include <iostream>
#include <vector>

using namespace std;
vector<unsigned long long> calcularTribonacci(const unsigned long long primeros[3], int cantidad) {
    vector<unsigned long long> secuencia;
    
    if (cantidad <= 0) {
        return secuencia;
    }

    if (cantidad >= 1) secuencia.push_back(primeros[0]);
    if (cantidad >= 2) secuencia.push_back(primeros[1]);
    if (cantidad >= 3) secuencia.push_back(primeros[2]);

    unsigned long long x = primeros[0];
    unsigned long long y = primeros[1];
    unsigned long long z = primeros[2];
    unsigned long long nuevo;

    for (int i = 3; i < cantidad; ++i) {
        nuevo = x + y + z;
        secuencia.push_back(nuevo);
        x = y;
        y = z;
        z = nuevo;
    }
    return secuencia;
}
int main() {
    unsigned long long iniciales[3];
    int totalTerminos;

    cout << "Por favor, ingrese los tres primeros números de la secuencia Tribonacci: ";
    cin >> iniciales[0] >> iniciales[1] >> iniciales[2];

    cout << "¿Cuántos términos desea obtener? ";
    cin >> totalTerminos;

    vector<unsigned long long> secuenciaTribonacci = calcularTribonacci(iniciales, totalTerminos);

    cout << "Los primeros " << totalTerminos << " términos de la secuencia Tribonacci son: ";
    for (size_t i = 0; i < secuenciaTribonacci.size(); ++i) {
        cout << secuenciaTribonacci[i];
        if (i < secuenciaTribonacci.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
