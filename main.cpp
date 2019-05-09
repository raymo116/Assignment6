#include <iostream>
#include <fstream>
#include "sorter.h"
#include<time.h>


using namespace std;

double* readFromFile(string myString);
void printTime(string myString);

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

    cout << "\nBubble Sort" << endl;
    printTime("Start");
    sorter::bubbleSort(myArray1, arrayLength);
    printTime("End");

    cout << "\nQuick Sort" << endl;
    printTime("Start");
    sorter::quickSort(myArray2, arrayLength);
    printTime("End");

    cout << "\nInsertion Sort" << endl;
    printTime("Start");
    sorter::insertionSort(myArray3, arrayLength);
    printTime("End");

    cout << "\nCycle Sort" << endl;
    printTime("Start");
    sorter::cycleSort(myArray4, arrayLength);
    printTime("End");


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

    string tempString = "";

    getline(myStream, tempString);
    double *myArray;

    try
    {
        int fileLength = stoi(tempString);
        myArray = new double[fileLength];

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

void printTime(string myString)
{
	time_t now = time(0); // current system date/time
	char* dt = ctime(&now); // convert in string form
	cout<< myString << " time: "<<dt;
}
