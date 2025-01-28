#pragma once
#include <iostream>

template <typename T>
class Nodo{
public: 
    T dato;
    Nodo<T> *next;
    Nodo<T> *prev;

    Nodo(){
    next = nullptr;
    prev = nullptr;
    }
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
        Nodo<T> *nuevo = new(std::nothrow) Nodo<T>;
        if(!nuevo){
            return false;
        }

        nuevo->dato = valor;
        nuevo->next = head;
        head = nuevo;
        return true;
    }
    
    bool insertarFinal(T error) { //método para insertar dato al final de la lista. regresa true o false
        Nodo<T> *tmp = nullptr, *nuevo = nullptr; //declaración apuntadores. tmp es para recorrer la lista y encontrar el último nodo. 
        //nuevo es para almacenar la dirección del nuevo nodo. ambos apuntadores los inicializamos en nullptr (no apuntan a ningún lugar)

        nuevo = new(std::nothrow) Nodo<T>; //creamos nuevo nodo. asigna memoria para un nuevo objeto de tipo Nodo, si falla, se establece a nullptr.
        if(!nuevo){ //si no se pudo asignar memoria, devuelve false diciendo que falló la asignación.
            return false;
        }
        nuevo->dato = error; //dirección de memoria a donde apunta eso. nuevo apunta a la dirección de memoria de dato

        if(!head){ //head apunta al primer nodo de la lista. Si head es nullptr, significa que la lista está vacía y el nuevo nodo se convierte en el primer nodo de la lista.
            head = nuevo;
            return true;
        }
    
        //busca el último nodo en la lista
        tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        //enlaza el nuevo nodo al final de la lista
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
        Nodo<T> *actual = head; 
        while(actual->next->next){ //no está inicializando actual. 
            actual = actual->next;
        }
        delete actual->next;
        actual->next = nullptr;
        return true;
    }

    int cuentaMenores(int dato){
        Nodo<T> *actual = head;
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
        Nodo<T> *actual = head; //se inicializa un apuntador actual que apunta al primer nodo (head)

        while(actual) { //bool miestras que haya nodos en la lista
            Nodo<T> *tmp = actual->next; //se crea un apuntador temporal que apunta al siguiente nodo
            delete actual; //elimina el nodo actual y libera memoria asociada con ese nodo
            actual = tmp; //actual se actualiza para apuntar al siguiente nodo (tmp)
        }
        head = nullptr; //al finalizar el bool, se establece nullptr a head para indicar que la lista está vacía
    }
    
private:    
    Nodo<T> *head;
};