#include <iostream>
#include "listaDL.h"

int main() {
    ListaDual miListaDL;

    for (int i = 0; i < 20; i++) {
        miListaDL.insertaFinal(i);
    }

    std::cout << "Lista en orden: ";
    miListaDL.imprime();

    std::cout << "Lista al revés: ";
    miListaDL.imprimeAlReves();

    return 0;
}