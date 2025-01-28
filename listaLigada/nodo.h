#pragma once

class Nodo{ //clase Nodo
public: //atributos públicos
    int dato; //variable int dato
    Nodo *next; //apuntador a un objeto de tipo Nodo. Apunta al siguiente nodo de la lista
    Nodo(); //constructor Nodo
};


class Lista{ //clase Lista
private: //atributos privados
    Nodo *head; //apuntador a un onjeto de tipo Nodo. Apunta a la cabeza de la lista ligada
public: //atributos públicos
    Lista(); //constructor
    ~Lista(); //destructor
    bool insertaFinal(int error); //método insertaFinal
    bool borrarElemento(int elemento); //método borrarElemento
    bool insertaInicio(int valor); //método insertaInicio
    bool insertaOrden(int valor); //método insertaOrden
    void imprimeLista(); //método imprimeLista
    void borrarLista(); //método borrarLista
};