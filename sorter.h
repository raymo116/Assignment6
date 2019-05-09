#include <iostream>
#include <fstream>

using namespace std;

class sorter
{

    static void quickSort(int myArray[], int size);
    static void insertionSort(int myArray[], int size);
    static void bubbleSort(int myArray[], int size);

    // https://www.geeksforgeeks.org/sleep-sort-king-laziness-sorting-sleeping/
    static void sleepSort(int myArray[], int size); // Sorts by sleeping for the correct amount of time

};
