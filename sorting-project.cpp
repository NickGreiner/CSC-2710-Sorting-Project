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
vector<int> mergeSort(vector<int> &dataset);
void quickSort(vector<int> &dataset);
void heapSort(vector<int> &dataset);

vector<int> loadDataset(string datafile);

void runTimeTest(vector<int> &dataset, int algoNum);

vector<int> merge(vector<int> left, vector<int> right);

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

  int n = testSet.size();
  int i, j;

  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++)
      if (testSet[j] > testSet[j+1])
        swap(testSet[j], testSet[j+1]);
  }
}

void insertionSort(vector<int> &dataset) {
  vector<int> testSet = dataset;

  int n = testSet.size();
  int i, key, j;

  for (i = 1; i < n; i++) {
    key = testSet[i];
    j = i - 1;

    while (j >= 0 && testSet[j] > key) {
      testSet[j + 1] = testSet[j];
      j = j - 1;
    }
    testSet[j + 1] = key;
  }
}

vector<int> mergeSort(vector<int> &dataset) {
  vector<int> testSet = dataset;

  if (testSet.size() <= 1)
    return testSet;
  int len = testSet.size() / 2;
  vector<int> left (testSet.begin(), testSet.begin() + len);
  vector<int> right(testSet.begin() + len, testSet.end());
  return merge(mergeSort(left), mergeSort(right));
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

  cout << "Current dataset: (" << datafile << ")\n\n";

  return numbers;
}

void runTimeTest(vector<int> &dataset, int algoNum) {
  using namespace std::chrono;

  string algoName;

  vector<int> sortedSet;

  auto start = high_resolution_clock::now();

  if (algoNum == 0){algoName = "selection sort"; selectionSort(dataset);}
  else if (algoNum == 1){algoName = "bubble sort"; bubbleSort(dataset);}
  else if (algoNum == 2){algoName = "insertion sort"; insertionSort(dataset);}
  else if (algoNum == 3){algoName = "merge sort"; sortedSet = mergeSort(dataset);}
  else if (algoNum == 4){algoName = "quick sort"; quickSort(dataset);}
  else if (algoNum == 5){algoName = "heap sort"; heapSort(dataset);}

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken by " << algoName << ": " << duration.count() << " microseconds" << endl;
}

vector<int> merge(vector<int> left, vector<int> right) {
	size_t ileft = 0, iright = 0;
	vector<int> results;
	while (ileft < left.size() && iright < right.size())
	  if (left[ileft] < right[iright])
	    results.push_back(left[ileft++]);
	  else
	    results.push_back(right[iright++]);
	while (ileft  < left.size() ) results.push_back(left [ileft++ ]);
	while (iright < right.size()) results.push_back(right[iright++]);
	return results;
}
