#pragma once
#include "Fraccion.h"

#define MAX_REN 10
#define MAX_COL 10

class MatFrac {
public:
	MatFrac() {
		renglones = 0;
		columnas = 0;
	}
	MatFrac(unsigned int renglones, unsigned int columnas) {
		this->renglones = renglones;
		if (this->renglones > MAX_REN) {
			std::cout << "Excede las dimensiones, limitado a " << MAX_REN << "\n";
			this->renglones = MAX_REN;
		}
			
		if (columnas > MAX_COL) {
			std::cout << "Excede las dimensiones, limitado a " << MAX_COL << "\n";
			this->columnas = MAX_COL;
		}
		else
			this->columnas = columnas;
	}
	void imprime();
	bool leerArchivo(std::string fileName);
private:
	unsigned int renglones;
	unsigned int columnas;
	Fraccion datos[MAX_REN][MAX_COL];
};

