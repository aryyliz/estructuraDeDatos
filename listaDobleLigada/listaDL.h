#pragma once

class NodoDual{
public:    
    int dato;
    NodoDual *next;
    NodoDual *prev;
    NodoDual(int valor);
    ~NodoDual();
};

class ListaDual{
private:
    NodoDual *head;
    NodoDual *tail;
public:
    ListaDual();
    ~ListaDual();
    bool insertaInicio(int dato);
    bool insertaFinal(int dato);
    bool insertaPosEsp(int valor, int posicion);
    bool insertaOrden(int valor);
    void imprime();
    void imprimeAlReves();
    void borrar();
    void borrarInicio();
    void borrarFinal();
    void borrarPosEsp(int posicion);
    bool borrarElemento(int elemento);
};