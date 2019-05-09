#include "sorter.h"
#include <cmath>

using namespace std;

// QUICK SORT
// =============================================================================
// =============================================================================

// A function fo switch numbers
void sorter::swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

// This function operates on a partition
int sorter::partition (int myArray[], int front, int back)
{
    // This sets the value of the pivot
    int pivot = myArray[back];

    // index of a smaller elements
    int smaller = (front - 1);

    // Iterates through all numbers ≤ the last in the partition
    for (int iterator = front; iterator <= back- 1; ++iterator)
    {
        // If current element is ≤ pivot
        if (myArray[iterator] <= pivot)
        {
            // Swaps the next number after smaller and the number at the iterator
            swap(myArray[++smaller], myArray[iterator]);
        }
    }

    // Swaps the elements one more time
    swap(myArray[++smaller], myArray[back]);
    // returns the index of the smaller value
    return (smaller);
}

// Main function for quicksort
void sorter::quickSort(int myArray[], int front, int back)
{
    // Base case is that front == back, at which it returns nothing
    if (front < back)
    {
        // Sorts one object into the correct location and then saves that index as the old partition
        int lastPartition = partition(myArray, front, back);

        // Sorts two subArrays
        quickSort(myArray, front, lastPartition - 1);
        // lastPartition is already in the right spot
        quickSort(myArray, lastPartition + 1, back);
    }
}

// Calls the function
void sorter::quickSort(int myArray[], int size)
{
    cout << "InsertionSort" << endl;

    // Implementation
    // ----------------------------------------

    // Calls the function to give fewer inputs
    quickSort(myArray, 0, size-1);

    // ----------------------------------------

    printArray(myArray, size);
}

// =============================================================================


// INSERTION SORT
// =============================================================================
// =============================================================================

void sorter::insertionSort(int myArray[], int size)
{
    cout << "InsertionSort" << endl;

    // Implementation
    // ----------------------------------------

    for (int outerLoop = 0; outerLoop < size; ++outerLoop)
    {
        // Creates a temp variable that holds the number being analyzed
        int currentNumber = myArray[outerLoop];
        // Creates the var for the inner loop. This starts one less than the object being analyzed
        int innerLoop = outerLoop-1;

        // While you haven't reached the begining of the array and while the secondary element is greater than the element being analyzed
        while((innerLoop > -1) && (myArray[innerLoop] > currentNumber))
        {
            // Shift the value on the left over by one
            myArray[innerLoop+1] = myArray[innerLoop--];
        }
        // Assign the given location to the current number
        myArray[innerLoop+1] = currentNumber;
    }

    // ----------------------------------------

    printArray(myArray, size);
}

// =============================================================================


// BUBBLE SORT
// =============================================================================
// =============================================================================

void sorter::bubbleSort(int myArray[], int size)
{
    cout << "BubbleSort" << endl;

    // Implementation
    // ----------------------------------------

    for (int outerLoop = 0; outerLoop < size; ++outerLoop)
    {
        for (int innerLoop = 0; innerLoop < size; ++innerLoop)
        {
            if(myArray[innerLoop] > myArray[innerLoop+1])
            {
                int temp = myArray[innerLoop];
                myArray[innerLoop] = myArray[innerLoop+1];
                myArray[innerLoop+1] = temp;
            }
        }
    }

    // ----------------------------------------

    printArray(myArray, size);
}

// =============================================================================


// TREE SORT
// =============================================================================
// =============================================================================

void sorter::cycleSort(int myArray[], int size)
{
    cout << "CycleSort" << endl;

    // Implementation
    // ----------------------------------------

    // Iterate through all of the elements of the array
    // The last one can be ignored because it will be put in place as a consequence of the rest
    for (int iterator = 0; iterator < size-1; iterator++)
    {
        // Temporary item to hold the value of the item that we're checking
        int tempItem = myArray[iterator];

        // The position that we're evaluating
        int evalPosition = iterator;

        // Iterate between the iterator and the end of the array
        for(int i = iterator+1; i < size; i++)
            // if the current value is less than the temp value, keep going
            // (we want to move it as far right as we possibly can)
            if (myArray[i] < tempItem)
                evalPosition++;

        // Continues if the item is already there
        if (evalPosition == iterator)
            continue;

        // Skips duplicate items
        while(tempItem == myArray[evalPosition])
            evalPosition++;

        // Puts the item in the correct position and takes the object in that
        // position and puts it in tempItem
        if(evalPosition != iterator)
            swap(tempItem, myArray[evalPosition]);

        // Continue operations
        while(evalPosition != iterator)
        {
            // The position that we're evaluating
            evalPosition = iterator;

            // find the correct position for the next item
            for(int i = iterator+1; i < size; i++)
                if (myArray[i] < tempItem)
                    evalPosition++;

            // Skips duplicate items
            while(tempItem == myArray[evalPosition])
                evalPosition++;

            // Puts the item in the correct position and takes the object in that
            // position and puts it in tempItem
            if(tempItem != myArray[evalPosition])
                swap(tempItem, myArray[evalPosition]);
        }
    }

    // ----------------------------------------

    printArray(myArray, size);
}

// =============================================================================

void sorter::printArray(int myArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << myArray[i] << (i<(size-1)?", ":"");
    }
    cout << endl << endl;
}
