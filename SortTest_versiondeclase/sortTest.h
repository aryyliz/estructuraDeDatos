#pragma once

#include <ctime>

class SortTest {
public:
    SortTest();
    ~SortTest();
    void generateRandomNumbers();
    void printData();
    bool setSize(unsigned int size);

    void bubbleSort();
	void insertionSort();
	void selectionSort();
    bool mergeSort();
private:
    void deleteArray();
    bool mergeSortExecute(unsigned int left, unsigned int right); // Internal function for executing Merge sort
    bool merge(unsigned int left, unsigned int middle, unsigned int right); // Helper function to merge two sorted subarrays
    unsigned int *data;
    unsigned int size;
};