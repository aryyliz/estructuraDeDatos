#include "MatFrac.h"
#include <fstream>

using namespace std;

void MatFrac::imprime() {
	for (unsigned int i = 0; i < renglones; i++) {
		for (unsigned int j = 0; j < columnas; j++) {
			datos[i][j].imprime();
			cout << " "; // Espacio de separacion entre fracciones
		}
		cout << "\n"; // ENTER en cada linea
	}
}

bool MatFrac::leerArchivo(std::string fileName) {
	ifstream file;

	file.open(fileName, ios::in);
	if (file.is_open() == false) {
		cout << "No se pudo abrir el archivo " << fileName << "\n";
		return false;
	}

	unsigned int tmpRen, tmpCols;

	if (!(file >> tmpRen) || !(file >> tmpCols)) {
		cout << "No se pudo cargar la matriz\n";
		file.close();
		return false;
	}

	if (tmpRen > MAX_REN || tmpCols > MAX_COL) {
		cout << "Excede las dimensiones\n";
		file.close();
		return false;
	}

	renglones = tmpRen;
	columnas = tmpCols;
	for (unsigned int i = 0; i < renglones; i++) {
		for (unsigned int j = 0; j < columnas; j++) {
			int n, d;

			if (!(file >> n) || !(file >> d)) {
				cout << "No se pudo cargar la fraccion " << i << ", " << j << " hacia la matriz\n";
				// Dejamos la matriz en 0s
				columnas = 0;
				renglones = 0;
				return false;
			}

			Fraccion tmp(n, d);
			datos[i][j] = tmp;
		}
	}

	file.close();
	return true;
}