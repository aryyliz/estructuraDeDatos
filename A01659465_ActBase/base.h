#pragma once //que sepa que ya se incluyó la liberería
//otra manera de hacerlo es #ifndef kjasdk_H, #define kjasdk_H... al final #endif (este es de C, no de C++)

//#define MAX_SIZE 20 //es una constante, si lo cambio, todo el código cambia. (inicializador)

class Base {
public: //(el public y private lo puedes poner varias veces. Todo lo public hasta arriba, y lo private hasta abajo)    
    Base::Base();

    void inicializa();
    void imprime();
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void mergeSort();
    
private:
    int* array;
    int tamano; //para que la clase siempre sepa su tamaño, refleja el valor interno del arreglo (estado actual del objeto)
};