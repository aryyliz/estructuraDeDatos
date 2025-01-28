#include <ctime>
#include <iostream>
#include "base.h"

//podemos poner el using namespace std; EN EL CPP DA IGUAL

void Base::inicializa(){
    srand(time(0));
    for (int i = 0; i < tamano; i++) { //si no ponemos las llaves del for, no pasa nada, pero es mejor practica
        array[i] = rand() % 100;
    }
}        

void Base::imprime(){
    //inicializar las iteraciones antes del for y eso
    for (int i = 0; i < tamano; i++) {
        std::cout << array[i] << " ";
    }
    std::cout<< std::endl;
}

void Base::bubbleSort() {
	for (int i = 0; i < -1; i++) {
		for (int j = 0; j < tamano -1; j++) {
			if (array[i] > array[i + 1]) {
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tamano;
			}
		}
	}
}

void Base::insertionSort() {
	for (int i = 1; i < tamano; i++) {
		int tamano = array[i];
		int j = i - 1;
		while (j >= 0 && tamano < array[j]) {
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = tamano;
	}
}

void Base::selectionSort() {
	for (int i = 0; i < tamano -1; i++) {
		int posicion = i;
		for (int j = i + 1; j < tamano; j++) {
			if (array[j] < array[posicion]) {
				posicion = j;
			}
		}
		if (posicion != i) {
			int act = array[i];
			array[i] = array[posicion];
			array[posicion] = act;
		}
	}
}

void Base::mergeSort() {
    
}