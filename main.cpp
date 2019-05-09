#include <iostream>
#include <fstream>
#include "sorter.h"

using namespace std;

double* readFromFile(string myString);

int main(int argc, char const *argv[])
{
    // double mainArray[] = {5, 4, 3, 2, 1};
    double *mainArray = readFromFile("test.txt");
    const int arrayLength = 5;

    double *myArray1 = new double[arrayLength];
    double *myArray2 = new double[arrayLength];
    double *myArray3 = new double[arrayLength];
    double *myArray4 = new double[arrayLength];

    for (int i = 0; i < arrayLength; i++)
    {
        myArray1[i] = mainArray[i];
        myArray2[i] = mainArray[i];
        myArray3[i] = mainArray[i];
        myArray4[i] = mainArray[i];
    }

    sorter::bubbleSort(myArray1, arrayLength);
    sorter::quickSort(myArray2, arrayLength);
    sorter::insertionSort(myArray3, arrayLength);
    sorter::cycleSort(myArray4, arrayLength);

    delete[] myArray1;
    delete[] myArray2;
    delete[] myArray3;
    delete[] myArray4;

    delete[] mainArray;

    return 0;
}

double* readFromFile(string myString)
{
    ifstream myStream;
    myStream.open(myString);

    int fileLength = 0;
    string tempString = "";

    while(getline(myStream, tempString))
    {
        fileLength++;
    }

    myStream.clear();
    myStream.seekg(0, ios::beg);

    double *myArray = new double[fileLength];

    try
    {
        for (int i = 0; i < fileLength; i++)
        {
            getline(myStream, tempString);
            myArray[i] = stod(tempString);
        }
    }
    catch(exception)
    {
        cout << "There was an error" << endl;
        exit(0);
    }

    myStream.close();
    return myArray;
}
