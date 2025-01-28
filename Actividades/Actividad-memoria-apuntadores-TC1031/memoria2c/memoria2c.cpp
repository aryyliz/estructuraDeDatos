/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 2c de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de 
 * demostrar apuntadores y su algebra
 *
 */

#include <iostream>

using namespace std;

int main() {
	int* ptr = nullptr;

	ptr = new(nothrow) int;
	if (ptr == nullptr) {
		cout << "No hay memoria\n";
		return 0;
	}

	*ptr = 5;
	cout << "El valor de ptr es: " << ptr << endl;
	cout << "El valor en ptr es: " << *ptr << endl;
	
	delete ptr;
	ptr = nullptr;

	return 0;
}