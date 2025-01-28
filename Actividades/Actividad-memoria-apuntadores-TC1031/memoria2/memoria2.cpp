/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 2 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de 
 * demostrar new y delete.
 *
 */

#include <iostream>

using namespace std;

#define MAX_SIZE 1000000000

int main() {
    long int* arrayPtr = nullptr;

    cout << "Asking for: "
        << (sizeof(long int) * MAX_SIZE) / (1024 * 1024 * 1024)
        << " Gbytes\n";

    arrayPtr = new long int[MAX_SIZE];
    if (!arrayPtr) {
        cerr << "Not enough memory" << endl;
        return 1;
    }

    cout << "Got them! Filling the array with long ints...\n";
    for (long int i = 0; i < MAX_SIZE; i++)
        arrayPtr[i] = i;

    cout << arrayPtr[MAX_SIZE / 2] << "\n";

    cout << "Revisa cuanto utiliza en el administrador de procesos de tu sistema operativo\n";
    cout << "Presiona ENTER para liberar la RAM y terminar";
    cin.ignore();

    delete[] arrayPtr;
    arrayPtr = nullptr;

    return 0;
}
