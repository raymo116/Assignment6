#include <iostream>
#include <fstream>

using namespace std;

class sorter
{
public:
    static void quickSort(int myArray[], int size);

    static void insertionSort(int myArray[], int size);
    static void bubbleSort(int myArray[], int size);

    static void cycleSort(int myArray[], int size); // Sorts by sleeping for the correct amount of time

private:
    static void printArray(int myArray[], int size);

    static void quickSort(int myArray[], int low, int high);
    static int partition(int myArray[], int start, int end);
    static void swap(int &a, int &b);
};
