#include <iostream>
#include "SortTest.h"

using namespace std;

SortTest::SortTest() {
    data = nullptr;
    size = 0;
}

SortTest::~SortTest() {
    deleteArray();
}

void SortTest::deleteArray() {
    if(data) {
        delete [] data;
        data = nullptr;
        size = 0;
    }
}

bool SortTest::setSize(unsigned int newSize) {
    if(newSize == 0)
        return false;
    deleteArray();
    data = new(nothrow) unsigned int[newSize];
    if(!data)
        return false;
    size = newSize;
    return true;
}

void SortTest::generateRandomNumbers() {
    for(unsigned int i = 0; i < size; i++)
        data[i] = rand() % size;
}

void SortTest::printData() {
    for(unsigned i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void SortTest::bubbleSort() {
    unsigned int i, j;

    for(i = 0; i < size; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(data[j] > data[j + 1]) {
                int tmp = 0;

                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}

void SortTest::insertionSort() {
	long int j = 0;  // porque no es unsigned int?
    unsigned int actual = 0;

    for(unsigned int i = 1; i < size; i++) {
        actual = data[i];
        j = i - 1;

        while (j >= 0 && data[j] > actual) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = actual;
    }
}

void SortTest::selectionSort() {
    unsigned int i, j, minIndex;

    for(i = 0; i < size - 1; i++) {
        minIndex = i;
        for(j = i + 1; j < size; j++) {
            if (data[j] < data[minIndex])
                minIndex = j;
        }
		
        if (minIndex != i) {
            unsigned int tmp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = tmp;
        }
    }
}

bool SortTest::mergeSort() {
    // Get started, full array
    return(mergeSortExecute(0, size - 1));
}

bool SortTest::mergeSortExecute(unsigned int start, unsigned int end) {
    unsigned int middle = 0;

    // base case
    if (start >= end)
        return true;

    middle = start + (end - start) / 2;

    mergeSortExecute(start, middle); // Sort the left half
    mergeSortExecute(middle + 1, end); // Sort the right half

    return(merge(start, middle, end)); // Merge the sorted halves
}

bool SortTest::merge(unsigned int left, unsigned int middle, unsigned int right) {
    unsigned int sizeLeft = middle - left + 1;
    unsigned int sizeRight = right - middle;
 
    unsigned int *leftArr = nullptr, *rightArr = nullptr;
    
    leftArr = new(nothrow) unsigned int[sizeLeft];
    if(!leftArr) {
        return false;
    }
    rightArr = new(nothrow) unsigned int[sizeRight];
    if(!rightArr) {
        delete [] leftArr;
        return false;
    }

   // Copy data to temporary arrays leftArr[] and rightArr[]
    for(unsigned int i = 0; i < sizeLeft; i++)
        leftArr[i] = data[left + i];
    for(unsigned int j = 0; j < sizeRight; j++)
        rightArr[j] = data[middle + 1 + j];

    unsigned int i = 0, j = 0, k = left;

    // Merge the two sorted arrays back into data[]
    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] <= rightArr[j]) {
            data[k] = leftArr[i];
            i++;
        } else {
            data[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < sizeLeft) {
        data[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < sizeRight) {
        data[k] = rightArr[j];
        j++;
        k++;
    }

    delete [] leftArr;
    delete [] rightArr;
    leftArr = nullptr;
    rightArr = nullptr;
    return true;
}
