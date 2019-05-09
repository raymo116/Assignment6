#include <iostream>
#include <fstream>

using namespace std;

class sorter
{
public:
    static void quickSort(double myArray[], int size);
    static void insertionSort(double myArray[], int size);
    static void bubbleSort(double myArray[], int size);
    static void cycleSort(double myArray[], int size); // Sorts by sleeping for the correct amount of time

private:
    static void printArray(double myArray[], int size);

    static void quickSort(double myArray[], int low, int high);
    static int partition(double myArray[], int start, int end);
    static void swap(double &a, double &b);
};
