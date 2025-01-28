#include <iostream>
#include "base.h"
#include <ctime>

Base::Base() { //constructor. asignamos memoria en el heap
    array = nullptr;
    size = 0;
}

Base::~Base() { //destructor que libera memoria
    if(array != nullptr){
        delete[] array;
        array = nullptr;
    }
}

void Base::setTamano(int tamano) { //método set
    if (array != nullptr){
        delete[] array;
        array = nullptr;
    }
    size = tamano;
    array = new(std::nothrow) int[size];
    if (array == nullptr){
        std::cout << "No se pudo asignar memoria" << std::endl;
        size = 0;
    }
}

