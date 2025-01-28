#pragma once
#include <iostream>

template <typename T>
class NodoListaLigada{
public: 
    T dato;
    NodoListaLigada<T> *next;
    NodoListaLigada<T> *prev;

    NodoListaLigada() : next(nullptr), prev(nullptr) {}
    NodoListaLigada(T valor) : dato(valor), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList{
public: 
    LinkedList(){
        head = nullptr;
    }
    
    ~LinkedList() {
        borraLista();
    }
     
    bool insertarInicio(T valor){
        NodoListaLigada<T> *nuevo = new(std::nothrow) NodoListaLigada<T>;
        if(!nuevo){
            return false;
        }

        nuevo->dato = valor;
        nuevo->next = head;
        head = nuevo;
        return true;
    }
    
    bool insertarFinal(T valor) {
        NodoListaLigada<T>* nuevo = new(std::nothrow) NodoListaLigada<T>(valor);
        if (!nuevo) {
            return false;
        }

        if (!head) {
            head = nuevo;
            return true;
        }
    
        NodoListaLigada<T>* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = nuevo;
        return true;
    }
    
    bool eliminaFinal(){
        if(!head){
            return false;
        }

        if(!head->next){ //si solo hya un elemento
            delete head;
            head = nullptr;
            return true;
        }
        NodoListaLigada<T> *actual = head; 
        while(actual->next->next){ //no está inicializando actual. 
            actual = actual->next;
        }
        delete actual->next;
        actual->next = nullptr;
        return true;
    }

    int cuentaMenores(int dato){
        NodoListaLigada<T> *actual = head;
        int contador = 0;
        while(actual){
            if(dato > actual->dato){
                contador++;
            }
            actual = actual->next;
        }
        return contador;
    }

    void borraLista(){ //método para borrar la lista (borra los nodos de la lista liberando memoria)
        NodoListaLigada<T> *actual = head; //se inicializa un apuntador actual que apunta al primer nodo (head)

        while(actual) { //bool miestras que haya nodos en la lista
            NodoListaLigada<T> *tmp = actual->next; //se crea un apuntador temporal que apunta al siguiente nodo
            delete actual; //elimina el nodo actual y libera memoria asociada con ese nodo
            actual = tmp; //actual se actualiza para apuntar al siguiente nodo (tmp)
        }
        head = nullptr; //al finalizar el bool, se establece nullptr a head para indicar que la lista está vacía
    }
    
    void imprimeLista(){
        NodoListaLigada<T> *tmp = head;
        while(tmp != nullptr){
            std::cout << tmp->dato << " ";
            tmp = tmp->next;
        }

        std::cout << "\n";
    }
    
private:    
    NodoListaLigada<T> *head;
};