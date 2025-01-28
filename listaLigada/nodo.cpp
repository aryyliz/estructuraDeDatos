#include <iostream>
#include "nodo.h"

Nodo::Nodo(){ //constructor Nodo
     next = nullptr; //inicializamos next
}

Lista::Lista(){ //constructor Lista
    head = nullptr; //inicializamos head
}

Lista::~Lista(){ //destructor
    borrarLista(); //ejecuta el borrarLista
}

bool Lista::insertaFinal(int error) { //método para insertar dato al final de la lista. regresa true o false
    Nodo *tmp = nullptr, *nuevo = nullptr; //declaración apuntadores. tmp es para recorrer la lista y encontrar el último nodo. 
    //nuevo es para almacenar la dirección del nuevo nodo. ambos apuntadores los inicializamos en nullptr (no apuntan a ningún lugar)

    nuevo = new(std::nothrow) Nodo; //creamos nuevo nodo. asigna memoria para un nuevo objeto de tipo Nodo, si falla, se establece a nullptr.
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


void Lista::imprimeLista(){ //método para imprimir lista
    Nodo *tmp = head;

    while(tmp){
        std::cout << tmp->dato << " ";
        tmp = tmp->next;
    }
    std::cout << "\n";
}

void Lista::borrarLista(){ //método para borrar la lista (borra los nodos de la lista liberando memoria)
    Nodo *actual = head; //se inicializa un apuntador actual que apunta al primer nodo (head)

    while(actual) { //bool miestras que haya nodos en la lista
        Nodo *tmp = actual->next; //se crea un apuntador temporal que apunta al siguiente nodo
        delete actual; //elimina el nodo actual y libera memoria asociada con ese nodo
        actual = tmp; //actual se actualiza para apuntar al siguiente nodo (tmp)
    }
    head = nullptr; //al finalizar el bool, se establece nullptr a head para indicar que la lista está vacía
}

bool Lista::borrarElemento(int elemento){
    if(!head){
        return false;
    }

    if(head->dato == elemento){
        Nodo *tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }

    Nodo *actual = head;
    Nodo *anterior = nullptr;

    while(actual && actual->dato != elemento){
        anterior = actual;
        actual = actual->next;
    }

    if(!actual){
        return false;
    }

    anterior->next = actual->next;
    delete actual;
    return true;
}

bool Lista::insertaInicio(int valor){
    Nodo *nuevo = new(std::nothrow) Nodo;
    if(!nuevo){
        return false;
    }

    nuevo->dato = valor;
    nuevo->next = head;
    head = nuevo;
    return true;
}

bool Lista::insertaOrden(int valor){
    Nodo *nuevo = nullptr;
    nuevo = new(std::nothrow) Nodo;

    if(!nuevo){
        return false;
    }    

    nuevo->dato = valor;
    nuevo->next = nullptr;

    if(!head){
        head = nuevo;
        return true;
    }

    if(valor < head->dato){
        nuevo->next = head;
        head = nuevo;
        return true;
    }

    Nodo *actual = head;
    while(actual->next && actual->next->dato < valor){
        actual = actual->next;
    }

    nuevo->next = actual->next;
    actual->next = nuevo;
    return true;
}