/*
Name: Sorting Project
Authors:  Nick Greiner, Matt Ray, Brysen Allen, Sam Mycroft
Class:  CSC-2710-01
Date:   9/22/2020

Description:  Program to to measure the time and number of basic
              operations (compares) different algorithms take to sort
              different datasets.

https://github.com/NickGreiner/CSC-2710-Sorting-Project
*/

#include<iostream>
#include<vector>
#include<chrono>

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int> &dataset);
void bubbleSort(vector<int> &dataset);
void insertionSort(vector<int> &dataset);
void mergeSort(vector<int> &dataset);
void quickSort(vector<int> &dataset);
void heapSort(vector<int> &dataset);

vector<int> loadDataset(string datafile);

void runTimeTest(vector<int> &dataset, int algoNum);

int main() {

  string datafile;
  vector<int> dataset;

  // Almost Sorted
  cout << "Enter almost sorted dataset: ";
  cin >> datafile;
  cout << endl;

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  // Randomly Distributed
  cout << "Enter randomly distributed dataset: ";
  cin >> datafile;
  cout << endl;

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  // Reverse Sorted
  cout << "Enter reverse sorted dataset: ";
  cin >> datafile;
  cout << endl;

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  // Duplicates
  cout << "Enter duplicates dataset: ";
  cin >> datafile;
  cout << endl;

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  return 0;
}
