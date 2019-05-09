#include <iostream>
#include "sorter.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int myArray1[] = {5, 4, 3, 2, 1};
    int myArray2[] = {5, 4, 3, 2, 1};
    int myArray3[] = {5, 4, 3, 2, 1};
    int myArray4[] = {5, 4, 3, 2, 1};
    int arrayLength = 5;
    sorter::bubbleSort(myArray1, arrayLength);
    sorter::quickSort(myArray2, arrayLength);
    sorter::insertionSort(myArray3, arrayLength);
    sorter::cycleSort(myArray4, arrayLength);

    return 0;
}
