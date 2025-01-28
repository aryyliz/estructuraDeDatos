#pragma once
#include "dlinkedlist.h"

template <typename T>
class HashTable{
public:
    using HashFunction = unsigned int (*)(T&, unsigned int tableSize);

    HashTable();
    ~HashTable();

    bool createTable(unsigned int blocks, HashFunction hashFunc);
    bool insertar(T dato);
    void borrar();
    void imprimirTabla();
    T* buscar(T dato);

private:
    ListaDL<T> *table;
    unsigned int size;

    HashFunction hashFunction;

    unsigned int getIndex(T dato);
};

template <typename T>
HashTable<T>::HashTable(){
    table = nullptr;
    size = 0;
}

template <typename T>
HashTable<T>::~HashTable(){
    borrar();
}

template <typename T>
bool HashTable<T>::createTable(unsigned int blocks, HashFunction hashFunc) {
    if(blocks == 0 || table || !hashFunc)                                                           
        return false;

    table = ListaDL<T>[blocks];
    if(!table){
        return false;
    }

    size = blocks;   
    // TODO: ¿Como inicializo la tabla hash?
    return true;
}

template <typename T>
bool HashTable<T>::insertar(T dato){
    unsigned int hashValue = 0;

    if(!table)
        return false;

    hashValue = getIndex(dato);
    if(!table[hashValue].insertarFinal(dato))
        return false;
    return true;
}

template <typename T>
void HashTable<T>::borrar() {
    if(!size)
        return;

    if(table) {
        delete [] table;
        table = nullptr;
        size = 0;
    }
}

template <typename T>
void HashTable<T>::imprimirTabla() {
    for(unsigned int i = 0; i < size; i++) {
        std::cout << "Entry[" << i << "]: " << table[i];
    } 
}

template <typename T>                                                                          
T* HashTable<T>::buscar(T dato) {                                                              
    if(!table)                                                                                 
        return nullptr;

    unsigned int index = getIndex(dato);

    for(auto elemento : table[index]){
        if(elemento == dato){
            return elemento;
        }
    }    

    // TODO: ¿Como encuentro el dato en la hashtable?
    // De momento regreso nullptr
    return(nullptr);
}

template <typename T>
unsigned int HashTable<T>::getIndex(T dato) {                                                  
    if(!hashFunction)                                                                          
        return 0;

    return hashFunction(dato) % size;
    // TODO: ¿Como encuentro el indice en la tabla?
    // Temporalmente regreso 0

}

