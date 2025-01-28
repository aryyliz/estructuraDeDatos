#include "nodo.h"
#include "ctime"
#include <iostream>

#define MAX_SIZE 20

int main() {
    Lista miLista;

    srand(time(NULL));
    for(unsigned int i = 0; i < MAX_SIZE; i++)
        if(!miLista.insertaFinal(i)) {
            std::cout << "No hubo memoria";
            return 0;
        }

    miLista.imprimeLista();
    miLista.insertaInicio(0);
    miLista.imprimeLista();
    miLista.borrarElemento(7);
    miLista.imprimeLista();
    miLista.insertaOrden(9);
    miLista.imprimeLista();

    //miLista.borrarLista();
   
    return 0;
}