
#include <iostream>
#include "Fraccion.h"

void Fraccion::imprime() {
    std::cout << numerador;
    if (denominador != 1)
        std::cout << "/" << denominador;
}

Fraccion Fraccion::suma(Fraccion a, Fraccion b) {
    int numRes = 0, denRes = 1;

    numRes = b.denominador * a.numerador + a.denominador * b.numerador;
    denRes = a.denominador * b.denominador;

    Fraccion res(numRes, denRes);
    return res;
}

void Fraccion::simplifica() {
    if (denominador < 0) {
        numerador *= -1;
        denominador *= -1;
    }

    int mcdVal = mcd(numerador, denominador);
    numerador /= mcdVal;
    denominador /= mcdVal;
}

int Fraccion::mcd(int a, int b) {
    int res = 1;

    while (res != 0) {
        res = a % b;
        a = b;
        b = res;
    }
    return a;
}
