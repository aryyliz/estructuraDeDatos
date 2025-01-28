#include <iostream>
#include "base.h"

int main() {
    Base base;
    int tamano; //tamaño del arreglo
    int elemento; //elemento a buscar en el arreglo
    int opcion(0); //menu para que el usuario elija una opcion. Inicializamos el valor de opcion a 0


    std::cout<<"Ingrese el tamaño del arreglo con el que quiera trabajar: "; //pedimos al usuario el tamaño del arreglo
    std::cin>>tamano;

    base.setTamano(tamano);
    base.inicializar();

    while(opcion != 6) { //loop para la selección de sorteo
        std::cout << "Elija una opción de sorteo: ";
        std::cout << "1) Bubble Sort"<< std::endl;
        std::cout << "2) Insertion Sort"<< std::endl;
        std::cout << "3) Selection Sort"<< std::endl;
        std::cout << "4) Merge Sort"<< std::endl;
        std::cout << "5) Quick Sort"<< std::endl;
        std::cout << "6) Binary Serch"<< std::endl;
        std::cout << "7) Salir"<< std::endl;
        std::cin >> opcion;

        //switch (el if de varias opciones)
        switch(opcion){
            case 1: //bubble
                std::cout << "Este es tu arreglo original: " << std::endl;
                base.imprimir();
                base.bubbleSort();
                std::cout << "El areglo con Bubble Sort es: " << std::endl;
                break; //el switch utiliza break

            case 2: //insertion
                std::cout << "Este es tu arreglo original: " << std::endl;
                base.imprimir();
                base.insertionSort();
                std::cout << "El areglo con Insertion Sort es: " << std::endl;
                break;
            
            case 3: //selection
                std::cout << "Este es tu arreglo original: " << std::endl;
                base.imprimir();
                base.selectionSort();
                std::cout << "El areglo con Selection Sort es: " << std::endl;
                break;

            case 4: //merge
                std::cout << "Este es tu arreglo original: " << std::endl;
                base.imprimir();
                base.mergeSort();
                std::cout << "El areglo con Merge Sort es: " << std::endl;
                break;

            case 5: //quick
                std::cout << "Este es tu arreglo original: " << std::endl;
                base.imprimir();
                base.quickSort();
                std::cout << "El areglo con Quick Sort es: " << std::endl;
                break;

            case 6: //búsqueda
                int busqueda; //variable que muestra el resultado d busqueda
                std::cout << "¿Qué elemento deseas buscar?: " << std::endl;
                std::cin >> elemento;
                base.quickSort();
                busqueda = base.binarySerch(elemento);

                if(busqueda != -1){
                    std::cout << "El elemento se encuentra en la posición: " << busqueda << std::endl;
                }
                else{
                    std::cout <<"El elemento que buscas no se encuentra en el arreglo" << std::endl;
                }
                break;

            case 7:
                return 0;

            default:
                std::cout << "Tu respuesta no es válida" << std::endl;            
                return 1;
        }

        base.imprimir();
    }

    return 0; //(0 es exitoso, lo que le dice al sistema operativo si la compilación estivo bien)
}