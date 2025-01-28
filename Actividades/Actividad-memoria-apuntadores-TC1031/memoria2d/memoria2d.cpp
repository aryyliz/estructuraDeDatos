/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 2d de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * demostrar apuntadores y su algebra
 *
 */

#include <iostream>

using namespace std;

#define MAX_SIZE 10

int main() {
	int* ptr = nullptr;

	ptr = new(nothrow) int[MAX_SIZE];
	if (ptr == nullptr) {
		cout << "No hay memoria\n";
		return 0;
	}

	for (unsigned int i = 0; i < MAX_SIZE; i++)
		ptr[i] = MAX_SIZE - i;

	cout << "El valor de ptr es: " << ptr << endl;
	cout << "El valor en ptr[6] es: " << ptr[6] << endl;
	cout << "El valor en *ptr + 6 es: " << *ptr + 6 << endl;
	cout << "El valor en *(ptr + 9) es: " << *(ptr + 9) << endl;

	delete [] ptr;
	ptr = nullptr;

	return 0;
}

