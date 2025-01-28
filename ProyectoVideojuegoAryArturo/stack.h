#include <iostream>
#pragma once

template <typename T>
class NodoStack{
public:    
    T dato;
    NodoStack<T> *next;

    NodoStack(T dato){
        this->next = nullptr;
        this->dato = dato; //si quiero inicializarlo con un T, se pone ... = T();
    }
};


template <typename T>

class Stack{
public: 
    Stack(){
        top = nullptr;
    }

    ~Stack(){
    }

    bool push(T dato){
        NodoStack<T> *nuevo = nullptr;
        nuevo = new(std::nothrow) NodoStack<T> (dato );
        if(!nuevo){
            return false;
        }
        nuevo->dato = dato;
        if(!top){
            top = nuevo;
            return true;
        }

        nuevo->next = top;
        top = nuevo;
        return true;
    }

    bool pop(){
        if(!top){
            return false;
        }    
        NodoStack<T> *tmp = top;
        top = top->next;
        delete tmp;
        return true;

    }

    bool isEmpty(){
        return top == nullptr;
    }

    T *getTop(){
        if(!top){
            return nullptr;
        }
        return &top->dato;
    }

private: 
    NodoStack<T> *top;
};