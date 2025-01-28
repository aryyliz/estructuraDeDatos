#include <iostream>
#include "listaDL.h"

NodoDual::NodoDual(int valor){
    this->next = nullptr;
    this->prev = nullptr;
    this->dato = valor;
};

NodoDual::~NodoDual(){

}

ListaDual::ListaDual(){
    head = nullptr;
    tail = nullptr;
}

ListaDual::~ListaDual(){
    borrar();
}

bool ListaDual::insertaInicio(int dato){
    NodoDual *nuevo = nullptr;
    nuevo = new(std::nothrow) NodoDual(dato);
    if(!nuevo){
        return false;    
    }

    nuevo->dato = dato;
    nuevo->next = head;

    if(head){
        head->prev = nuevo;
    }
    head = nuevo;
    return true;
}

bool ListaDual::insertaFinal(int dato){
    NodoDual *nuevo = nullptr;
    nuevo = new(std::nothrow) NodoDual(dato);
    if(!nuevo){
        std::cout << "No se pudo asiganr memoria para el nodo" << std::endl; 
        return false;
    }

    if(!tail){
        head = tail = nuevo;
        std::cout << "Insertando como primer elemento: " << dato << std::endl;
        return true;
    }

    nuevo->prev = tail;
    tail->next = nuevo;
    tail = nuevo;
    std::cout << "Insertando al final: " << dato << std::endl;
    return true;
}

bool ListaDual::insertaPosEsp(int valor, int posicion){
    if(posicion < 1){
        return false;
    }

    if(posicion == 1){
        return insertaFinal(valor);
    }

    NodoDual *nuevo = nullptr;
    nuevo = new(std::nothrow) NodoDual(valor);

    if(!nuevo){
        return false;
    }

    NodoDual *tmp = head;

    for(int i = 1; tmp != nullptr && i < posicion -1; i++){
        tmp = tmp->next;
    }

    if(tmp == nullptr){
        return false;
    }

    nuevo->next = tmp->next;
    nuevo->prev = tmp;
    
    if(tmp->next != nullptr){
        tmp->next->prev = nuevo;
    }

    tmp->next = nuevo;
    return true;
}

bool ListaDual::insertaOrden(int valor){
    NodoDual *nuevo = nullptr;
    nuevo = new(std::nothrow) NodoDual(valor);

    if(!nuevo){
        return false;
    }

    nuevo->next = nullptr;

    if(!head){
        head = tail = nuevo;
        return true;
    }

    if(valor < head->dato){
        nuevo->next = head;
        head->prev = nuevo;
        head = nuevo;
        return true;
    }

    NodoDual *actual = head;
    while(actual->next && actual->next->dato < valor){
        actual = actual->next;
    }

    nuevo->next = actual->next;
    nuevo->prev = actual;

    if(actual->next){
        actual->next->prev = nuevo;
    } else{
        tail = nuevo;
    }

    actual->next = nuevo;
    return true;
}

void ListaDual::imprime(){
    if(!head){
        return;
    }

    NodoDual *tmp = head;

    while(tmp){
        std::cout << tmp->dato << " ";
        tmp =tmp->next;
    }
    std::cout << "\n";
}


void ListaDual::imprimeAlReves(){
    if(!head) {
        return;
    }

    NodoDual *tmp = tail;

    while(tmp){
        std::cout << tmp->dato << " ";
        tmp = tmp->prev;
    }
    std::cout << "\n";
}

void ListaDual::borrar(){
    while (head) {
        NodoDual *tmp = head;
        head = head->next;
        if(head){
            head->prev = nullptr;
        }
        delete tmp;
    }
    tail = nullptr;
}

void ListaDual::borrarInicio(){
    if(!head){
        return;
    }

    NodoDual *tmp = head;
    head = head->next;

    if(head != nullptr){
        head->prev = nullptr;
    }
    else{
        tail = nullptr;
    }

    delete tmp;
    return;
}

void ListaDual::borrarFinal(){
    if(!head){
        return;
    }

    NodoDual *tmp = tail;
    tail = tail->prev;

    if(tail != nullptr){
        tail->next = nullptr;
    }
    else{
        head = nullptr;
    }

    delete tmp;
    return;
}

bool ListaDual::borrarElemento(int elemento){
    if(!head){
        return false;
    }

    if(head->dato == elemento){
        NodoDual *tmp = head;
        head = head->next;

        if(head){
            head->prev = nullptr;
        }
        else{
            tail = nullptr;
        }
        delete tmp;
        return true;
    }

    NodoDual *actual = head;
    while(actual && actual->dato != elemento){
        actual = actual->next;
    }
    if(!actual){
        return false;
    }

    if(actual->next){
        actual->next->prev = actual->prev;
    }
    else{
        tail = actual->prev;
    }

    if(actual->prev){
        actual->prev->next = actual->next;
    }

    delete actual;
    return true;
}

void ListaDual::borrarPosEsp(int posicion){
    if(!head || posicion < 1){
        return;
    }

    if(posicion == 1){
        return borrarInicio();
    }

    NodoDual *tmp = head;

    for(int i = 1; tmp != nullptr && i < posicion; i++ ){
        tmp = tmp->next;
    }

    if(tmp == nullptr){
        return;
    }

    if(tmp->next != nullptr){
        tmp->next->prev = tmp->prev;
    }

    if(tmp->prev != nullptr){
        tmp->prev->next = tmp->next;
    }

    delete tmp;
    return;
}