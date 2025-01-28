
#include <iostream>
#include "Fraccion.h"
#include "MatFrac.h"

int main() {
    MatFrac mat1;

    if (!mat1.leerArchivo("matriz1.txt"))
        return 0;
    mat1.imprime();
    // TODO Leer matriz2.txt a mat2
    // TODO Imprimir mat2
    // TODO Sumar mat1 y mat2 hacia matRes
    // TODO Imprimir matRes
    // TODO Giardar martRes a matres.txt
    return 0;
}