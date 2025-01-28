#include <iostream> //librería standar (cin y cout)
#include "base.h"

using namespace std; //no es buena practica ponerlo siempre 

int main() {
    Base base();
    int tamano;
    std::cout<<"Ingrese el tamaño del arreglo con el que quiera trabajar: "; //pedimos al usuario el tamaño del arreglo
    std::cin>>tamano;

    std::cout<<"Elija una opción de sorteo: ";

    int opcion; //menu para que el usuario elija una opcion
    std::cout<<"1) Bubble Sort"<< std::endl;
    std::cout<<"2) Insertion Sort"<< std::endl;
    std::cout<<"3) Selection Sort"<< std::endl;
    std::cout<<"4) Merge Sort"<< std::endl;
    std::cout<<"5) Salir"<< std::endl;
    std::cin>>opcion;

    if (opcion == 1){ //bubbleSort
        base.bubbleSort();
    }
    else if (opcion == 2){ //insertionSort
        base.selectionSort();
    }
    else if (opcion == 3){
        base.selectionSort();
    }
    else if (opcion == 4){
        base.mergeSort();
    }
    else {
        std::cout<<"Opcion no válida";
    }

    return 0; //(0 es exitoso, lo que le dice al sistema operativo si la compilación estivo bien)
}