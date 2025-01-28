#pragma once
#include <iostream>
#include "dobleListaLigadaT.h"
#include "monstruo.h"

class HashTable {
public: 
    HashTable(){
        table = nullptr; 
        size = 0;

    }

    bool createTable(unsigned int nSize);
    bool insertar(Monstruo dato);
    bool borrar(Monstruo dato);
    bool borrarTabla();
    Monstruo *buscar(std::string name);

private: 
    unsigned int hashMonstruoToIndex(Monstruo dato);
    ListaDual<Monstruo> *table;
    unsigned int size;
    unsigned int hash(Monstruo hash);
};