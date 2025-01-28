#pragma once
#include "queueT.h"

template<typename T>

class NodoArbol{
public:
    T dato;
    NodoArbol<T> *left;
    NodoArbol<T> *right;
    NodoArbol(T dato) : dato(dato), left(nullptr), right(nullptr){}
};

template<typename T>
class ArbolBinario{
public:
    ArbolBinario(){
        root = nullptr;
    }

    ~ArbolBinario(){
        borrarArbol();
    }
    
    bool inserta(T dato){
        return insertaRecursivo(root, dato);
    }

    bool insertaRecursivo(NodoArbol<T> *&nodo, T dato){
        if(!nodo){
            nodo = new(std::nothrow) NodoArbol<T>(dato);
            if(!nodo){
                return false;
            }
            return true;
        }
        if(dato < nodo->dato){
            return insertaRecursivo(nodo->left, dato);
        }
        else if(dato > nodo->dato){
            return insertaRecursivo(nodo->right, dato);
        }
        return false;
    }

    bool imprimeInOrder(){
        if(!root){
            return false;
        }
        return imprimeInOrderRecursivo(root);
    }

    bool imprimeInOrderRecursivo(NodoArbol <T> *nodo){
        if(!nodo){
            return false;
        }
        imprimeInOrderRecursivo(nodo->left);
        std::cout << nodo->dato << " ";
        imprimeInOrderRecursivo(nodo->right);
        return true;
    }

    bool imprimePreOrder(){
        if(!root){
            return false;
        }
        return imprimePreOrderRecursivo(root);
    }

    bool imprimePreOrderRecursivo(NodoArbol <T> *nodo){
        if(!nodo){
            return false;
        }
        std::cout << (nodo)->dato << " ";
        imprimePreOrderRecursivo(nodo->left);
        imprimePreOrderRecursivo(nodo->right);
        return true;
    }

    bool imprimePostOrder(){
        if(!root){
            return false;
        }
        return imprimePostOrderRecursivo(root);
    }
    bool imprimePostOrderRecursivo(NodoArbol<T> *nodo){
        if(!nodo){
            return false;
        }
        imprimePostOrderRecursivo(nodo->left);
        imprimePostOrderRecursivo(nodo->right);
        std::cout << nodo->dato << " ";
        return true;
    }

    bool imprimeNiveles(){
    if(!root){
        return false;
    }

    Queue<NodoArbol<T>*> queue;
    queue.enqueue(root);

    while(!queue.queueVacia()){
        NodoArbol<T>* actual = queue.verFrente();
        queue.dequeue();

        std::cout << actual->dato << " ";

        if(actual->left != nullptr){
            queue.enqueue(actual->left);
        }

        if(actual->right != nullptr){
            queue.enqueue(actual->right);
        }
    }

    std::cout << std::endl;
    return true;
}


    bool borrarArbol(){
        if(!root){
            return false;
        }
        borrarArbolRecursivo(root);
        root = nullptr;
        return true;
    }

    bool borrarArbolRecursivo(NodoArbol<T> *nodo){
        if(!nodo){
            return false;
        }
        borrarArbolRecursivo(nodo->left);
        borrarArbolRecursivo(nodo->right);
        delete nodo;
        return true;
    }

    T* busqueda(T dato){
        return(busquedaRecursiva(root, dato));
    }

    T* busquedaRecursiva(ArbolBinario<T> *actual, T data){
        if(!actual){
            return nullptr;
        }

        if(data < actual->info){
            return(busquedaRecursiva(actual->left, data));
        }

        else if(data > actual->info){
            return(busquedaRecursiva(actual->right, data));
        }

        return &actual->dato;
    }

private:
    NodoArbol<T> *root;
};