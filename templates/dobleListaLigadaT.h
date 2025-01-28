#pragma once
#include <iostream>

template <typename T>
class NodoDual{
public: 
    T dato;
    NodoDual<T> *next;
    NodoDual<T> *prev;

    NodoDual(T valor){
        this->dato = valor;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <typename T>
class ListaDual{
private:
    NodoDual<T> *head;
    NodoDual<T> *tail;
public:
    ListaDual(){
        head = nullptr;
        tail = nullptr;
    }

    ~ListaDual(){
        delete();
    }

    bool insertaInicio(T dato){
        NodoDual<T> *nuevo = nullptr;
        nuevo = new(std::nothrow) NodoDual<T>(dato);
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

    bool insertaFinal(T dato){
        NodoDual<T> *nuevo = nullptr;
        nuevo = new(std::nothrow) NodoDual<T>(dato);
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

    bool insertaPosEsp(T valor, T posicion){
        if(posicion < 1){
            return false;
        }

        if(posicion == 1){
            return insertaFinal(valor);
        }

        NodoDual<T> *nuevo = nullptr;
        nuevo = new(std::nothrow) NodoDual<T>(valor);

        if(!nuevo){
            return false;
        }

        NodoDual<T> *tmp = head;

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

    bool insertaOrden(T valor){
        NodoDual<T> *nuevo = nullptr;
        nuevo = new(std::nothrow) NodoDual<T>(valor);

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

        NodoDual<T> *actual = head;
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

    void imprime(){
        if(!head){
            return;
        }

        NodoDual<T> *tmp = head;

        while(tmp){
            std::cout << tmp->dato << " ";
            tmp =tmp->next;
        }
        std::cout << "\n";
    }

    void imprimeAlReves(){
        if(!head) {
            return;
        }

        NodoDual<T> *tmp = tail;

        while(tmp){
            std::cout << tmp->dato << " ";
            tmp = tmp->prev;
        }
        std::cout << "\n";
    }

    void borrar(){
        while (head) {
            NodoDual<T> *tmp = head;
            head = head->next;
            if(head){
                head->prev = nullptr;
            }
            delete tmp;
        }
        tail = nullptr;
    }

    void borrarInicio(){
        if(!head){
            return;
        }

        NodoDual<T> *tmp = head;
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

    void borrarFinal(){
        if(!head){
            return;
        }

        NodoDual<T> *tmp = tail;
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

    bool borrarElemento(T elemento){
    if(!head){
        return false;
    }

    if(head->dato == elemento){
        NodoDual<T> *tmp = head;
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

    NodoDual<T> *actual = head;
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
    void borrarPosEsp(T posicion){
        if(!head || posicion < 1){
            return;
        }

        if(posicion == 1){
            return borrarInicio();
        }

        NodoDual<T> *tmp = head;

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

};