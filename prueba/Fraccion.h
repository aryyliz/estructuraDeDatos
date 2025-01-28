#pragma once
#include <iostream>

class Fraccion {
public:
    Fraccion() {
        numerador = 0;
        denominador = 1;
    }

    Fraccion(int numerador, int denominador) {
        this->numerador = numerador;
        if(denominador != 0)
            this->denominador = denominador;
        else {
            std::cout << "Se recibio un 0 en el denominador, se cambio por 1" << std::endl;
            this->denominador = 1;
        }
        simplifica();
    }
    
    void imprime();

    static Fraccion suma(Fraccion a, Fraccion b);
private:
    void simplifica();
    int mcd(int a, int b);
    int numerador;
    int denominador;
};

