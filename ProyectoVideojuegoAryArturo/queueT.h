#pragma once 
#include <iostream>

template <typename T>
class Nodo{
public:
    T dato;
    Nodo<T> *next;

    Nodo(T valor){
        next = nullptr;
        dato = valor;
    }
};

template <typename T>
class Queue{
private:
    Nodo<T> *head;
    Nodo<T> *tail;

public:
    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    ~Queue(){
        while(head){
            dequeue();
        }       
    }
    bool enqueue(T valor){
        Nodo<T> *nuevo = nullptr;
        nuevo = new(std::nothrow) Nodo<T>(valor);
            
        if(!nuevo){
            return false;
        }

        if(!tail){
            tail = head = nuevo;
            return true;
        }

        tail->next = nuevo;
        tail = nuevo;

        return true;
    }

    bool dequeue(){
        if(!head){
            return false;
        }

        Nodo<T> *tmp = head;
        head = head->next;
        if(!head){
            tail = nullptr;
        }

        delete tmp;
        return true;
    }

    void imprimir(){
        Nodo<T> *actual = head;
        while(actual) {
            std::cout << actual->dato << " ";
            actual = actual->next;
        }
        std::cout << "\n";
    }

    bool queueVacia(){
        return head == nullptr;
    }

    T* verFrente(){
        if(!head){
            std::cout << "La queue está vacía" << std::endl;
            return nullptr;
        }
        return &head->dato;
    }
};