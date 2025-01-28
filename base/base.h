#pragma once

class Base {
private: 
    int *array;
    int size;

    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);
    int partir(int start, int end);
    void quickSort(int start, int end);

public: 
    Base();
    ~Base();
    void setTamano(int tamano); //tamano es diferente a size
    void inicializar();
    void imprimir();

    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void mergeSort();
    void quickSort();
    int binarySerch(int valor);
};