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

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

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

  if (datafile == "1") {datafile = "almost-sorted";}

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  cout << endl;

  // Randomly Distributed
  cout << "Enter randomly distributed dataset: ";
  cin >> datafile;
  cout << endl;

  if (datafile == "1") {datafile = "randomly-distributed";}

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  cout << endl;

  // Reverse Sorted
  cout << "Enter reverse sorted dataset: ";
  cin >> datafile;
  cout << endl;

  if (datafile == "1") {datafile = "reverse-sorted";}

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  cout << endl;

  // Duplicates
  cout << "Enter duplicates dataset: ";
  cin >> datafile;
  cout << endl;

  if (datafile == "1") {datafile = "duplicates";}

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  return 0;
}

void selectionSort(vector<int> &dataset) {
  vector<int> testSet = dataset;

  int n = testSet.size();
  int i, j, min_idx;

  for (i = 0; i < n-1; i++) {
    min_idx = i;
    for (j = i+1; j < n; j++)
    if (testSet[j] < testSet[min_idx])
        min_idx = j;

    swap(testSet[min_idx], testSet[i]);
  }
}

void bubbleSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
}

void insertionSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
}

void mergeSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
}

void quickSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
}

void heapSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
}

vector<int> loadDataset(string datafile) {
  ifstream is(datafile);
  istream_iterator<int> start(is), end;
  vector<int> numbers(start, end);
  cout << "Read " << numbers.size() << " numbers" << endl;

  cout << "Current dataset: (" << datafile << ")\n";

  return numbers;
}

void runTimeTest(vector<int> &dataset, int algoNum) {
  using namespace std::chrono;

  string algoName;

  auto start = high_resolution_clock::now();

  if (algoNum == 0){algoName = "selection sort"; selectionSort(dataset);}
  else if (algoNum == 1){algoName = "bubble sort"; bubbleSort(dataset);}
  else if (algoNum == 2){algoName = "insertion sort"; insertionSort(dataset);}
  else if (algoNum == 3){algoName = "merge sort"; mergeSort(dataset);}
  else if (algoNum == 4){algoName = "quick sort"; quickSort(dataset);}
  else if (algoNum == 5){algoName = "heap sort"; heapSort(dataset);}

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken by " << algoName << ": " << duration.count() << " microseconds" << endl;
}
