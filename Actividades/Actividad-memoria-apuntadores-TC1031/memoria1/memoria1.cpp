/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 1 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * demostrar las limitantes del stack.
 *
 * Al incrementar el tamaño de MAX_SIZE
 * se llega al límite donde el programa
 * ya no ejecuta debido a que excede el
 * tamaño máximo del stack.
 */

#include <iostream>

using namespace std;

#define MAX_SIZE 10000000

int main() {
    // declaramos un arreglo de tamaño MAX_SIZE
    int array[MAX_SIZE];

    cout << "Llenando el arreglo...\n";
    // Llenamos el arreglo
    for (int i = 0; i < MAX_SIZE; i++)
        array[i] = i;

    // Imprimimos el elemento del "centro"
    cout << array[MAX_SIZE / 2] << endl;
    return 0;
}