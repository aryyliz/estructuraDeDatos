#pragma once
#include "queueT.h"

template<typename T>

class NodoAVL{
public:
    T dato;
    int altura;
    NodoAVL<T> *left;
    NodoAVL<T> *right;
    NodoAVL(T dato) : dato(dato), altura(0) left(nullptr), right(nullptr){}
};

template<typename T>
class ArbolAVL{
public: 
    ArbolAVL(){
        root = nullptr;
    }

    ~ArbolAVL(){
        borrarArbol();
    }
 
    int getAltura(NodoAVL<T>* nodo){
        if(!nodo){
            return -1; 
        }
        return nodo->altura;
    }

    int revisaBalance(NodoAVL<T>* nodo){
        if(!nodo){
            return -1;
        }
        return getAltura(nodo->left) - getAltura(nodo->right);
    }

    void calculaAltura(NodoAVL<T>* nodo){
        if(nodo){
            nodo->altura = 1 + std::max(getAltura(nodo->left), getAltura(nodo->right));
        }
    }

    void balancea(NodoAVL<T> *&nodo){
        if(revisaBalance(nodo) > 1){ //izquierda mayor
            if(revisaBalance(nodo->left) >= 0){ //izquierda fue mayor por fuera
                return rotacionDerecha(nodo);
            }
            if(revisaBalance(nodo->left) < 0){ //derecha fue mayor por dentro
                return rotacionDobleDerecha(nodo);
            }
        }

        if(revisaBalance(nodo) < -1){ //derecha mayor
            if(revisaBalance(nodo->right) <= 0){ //derecha due mayor por fuera
                return rotacionIzquierda(nodo);
            }
            if(revisaBalance(nodo->right) > 0){ //izquierda fue mayor por dentro
                return rotacionDobleIzquierda(nodo);
            }
        }
    }

    NodoAVL<T>* rotacionDerecha(NodoAVL<T>* nodo){
        NodoAVL<T>* nuevaRaiz = nodo->left;
        NodoAVL<T>* tmp = nuevaRaiz->right;
        nuevaRaiz->right = nodo;
        nodo->left= tmp;

        //NodoAVL<T>* tmp = nodo->right;
        //NodoAVL<T>* nuevaRaiz->right = nodo->right;
        //NodoAVL<T>* nodo->right->left = tmp;

        calculaAltura(nodo);
        calculaAltura(nuevaRaiz);
        return nuevaRaiz;
    }

    NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* nodo){
        NodoAVL<T>* nuevaRaiz = nodo->right;
        NodoAVL<T>* tmp = nuevaRaiz->left;

        nuevaRaiz->left = nodo;
        nodo->right = tmp;

        //NodoAVL<T>* tmp = nuevaRaiz->left;
        //NodoAVL<T>* nuevaRaiz->left = nodo;
        //NodoAVL<T>* nodo->right = tmp;

        calculaAltura(nodo);
        calculaAltura(nuevaRaiz);
        return nuevaRaiz;
    }    

    NodoAVL<T>* rotacionDobleDerecha(NodoAVL<T>* nodo){
        nodo->left = rotacionIzquierda(nodo->left);
        return rotacionDerecha(nodo);
    }

    NodoAVL<T>* rotacionDobleIzquierda(NodoAVL<T>* nodo){
        nodo->right = rotacionDerecha(nodo->right);
        return rotacionIzquierda(nodo);
    }


    bool inserta(T dato){
        return insertaRecursivo(root, dato);
    }

    bool insertaRecursivo(NodoAVL<T> *&nodo, T dato){
        if(!nodo){
            nodo = new(std::nothrow) NodoAVL<T>(dato);
            if(!nodo){
                return false;
            }
            return true;
        }
        if(dato < nodo->dato){
            return insertaRecursivo(nodo->left, dato){
                calculaAltura(nodo);
                balancea(nodo);
                return true;
            }
            else{
                return false;
            }
        }
        else if(dato > nodo->dato){
            if(insertaRecursivo(nodo->right, dato)){
                calculaAltura(nodo);
                balancea(nodo);
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }

    bool imprimeInOrder(){
        if(!root){
            return false;
        }
        return imprimeInOrderRecursivo(root);
    }

    bool imprimeInOrderRecursivo(NodoAVL <T> *nodo){
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

    bool imprimePreOrderRecursivo(NodoAVL <T> *nodo){
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
    bool imprimePostOrderRecursivo(NodoAVL<T> *nodo){
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

    Queue<NodoAVL<T>*> queue;
    queue.enqueue(root);

    while(!queue.queueVacia()){
        NodoAVL<T>* actual = queue.verFrente();
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

    bool borrarArbolRecursivo(NodoAVL<T> *nodo){ //agregar lo de los balanceos
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

    T* busquedaRecursiva(ArbolAVL<T> *actual, T data){
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
    ArbolAVL<T> *root;
};