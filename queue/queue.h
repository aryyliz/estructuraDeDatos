#pragma once 
#include <iostream>

class Nodo{
public:
    int dato;
    Nodo *next;

    Nodo(int valor);
};

class Queue{
private:
    Nodo *head;
    Nodo *tail;
public:

    Queue();
    ~Queue();
    bool enqueue(int valor);
    bool dequeue();
    void imprimir();
    bool queueVacia();
    int verFrente();
};