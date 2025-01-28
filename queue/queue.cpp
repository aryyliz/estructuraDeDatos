#include "queue.h"

Nodo::Nodo(int valor){
    next = nullptr;
    dato = valor;
}

Queue::Queue(){
    head = nullptr;
    tail = nullptr;
}

Queue::~Queue(){
    while(head){
        dequeue();
    }
}

bool Queue::enqueue(int valor){ //insertar
    Nodo *nuevo = nullptr;
    nuevo = new(std::nothrow) Nodo(valor);
    
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

bool Queue::dequeue(){ //eliminar
    if(!head){
        return false;
    }

    Nodo *tmp = head;
    head = head->next;
    tmp->next = nullptr;
    delete tmp;
    return true;
}

void Queue::imprimir() {
    Nodo *actual = head;
    while(actual) {
        std::cout << actual->dato << " ";
        actual = actual->next;
    }
    std::cout << "\n";
}

bool Queue::queueVacia(){
    return head == nullptr;
}

int Queue::verFrente(){
    if(!head){
        std::cout << "La queue está vacía" << std::endl;
    }
    return head->dato;
}