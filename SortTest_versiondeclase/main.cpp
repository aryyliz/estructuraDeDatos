#include <iostream>
#include "SortTest.h"

using namespace std;

int main() {
    unsigned int size = 0;
    SortTest myTest;

	srand(time(0));

    do {
        cout << "Dame el size: ";
        cin >> size;
    } while(size == 0);

    if(!myTest.setSize(size)) {
        cout << "No hubo memoria\n";
        return 0;
    }
	// Bubble Sort
    myTest.generateRandomNumbers();
    cout << "El arreglo original es:" << endl;
    myTest.printData();

    myTest.bubbleSort();
    cout << "El arreglo ordenado por Bubble Sort es:" << endl;
    myTest.printData();

	//Insertion Sort
	myTest.generateRandomNumbers();
    cout << "\nEl arreglo original es:" << endl;
    myTest.printData();

    myTest.insertionSort();
    cout << "El arreglo ordenado por Insertion Sort es:" << endl;
    myTest.printData();

	// Selection Sort
	myTest.generateRandomNumbers();
    cout << "\nEl arreglo original es:" << endl;
    myTest.printData();

    myTest.selectionSort();
    cout << "El arreglo ordenado por Selection Sort es:" << endl;
    myTest.printData();

    // Merge Sort
	myTest.generateRandomNumbers();
    cout << "\nEl arreglo original es:" << endl;
    myTest.printData();

    if(myTest.mergeSort())
        myTest.printData();
    else
        cout << "out of memory\n";
}