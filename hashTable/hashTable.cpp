#include "hashTable.h"

bool HashTable::createTable(unsigned int nSize){
    if(nSize == 0 || table != nullptr){
        return false;
    }

    table = new(std::nothrow) ListaDual<Monstruo>[nSize];
    if(!table){
        return false;
    }

    size = nSize;
    return true;
}

bool HashTable::borrarTabla(){
    if(table){
        delete [] table;
        table = nullptr;
        size = 0;
        return true;
    }
    return false;
}

unsigned int HashTable::hashMonstruoToIndex(Monstruo dato){
    int hashIndex = 0;
    return (hashIndex = hash % size);
}

unsigned int HashTable::hash(Monstruo dato){
    std::string name;
    unsigned int hashValor = 0, len = 0;
    name = dato.getName;
    len = name.lenght();
    for (unsigned int i = 0; i < len; i++) {
        hashValor = hashValor + name[i];
    }
    return hashValor;
}

bool HashTable::insertar(Monstruo dato){
    unsigned int index = 0;
    if(!table){
        return false;
    }

    index = hashMonstruoToIndex(dato);
    return table[index].insertaFinal(dato);
}

bool HashTable::borrar(Monstruo dato){
    return true;
}

