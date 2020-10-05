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

// Sorting Functions
vector<int> selectionSort(vector<int> &dataset);
vector<int> bubbleSort(vector<int> &dataset);
vector<int> insertionSort(vector<int> &dataset);
vector<int> mergeSort(vector<int> &dataset);
vector<int> quickSort(vector<int> &dataset);
vector<int> heapSort(vector<int> &dataset);

// Functions to load / write datasets
vector<int> loadDataset(string datafile);
void writeDataset(string datafile);

// Time Test Function
void runTimeTest(vector<int> &dataset, int algoNum);

// Functions used in recursive sort functions
vector<int> merge(vector<int> left, vector<int> right);
void qs(vector<int> &values, int left, int right);
int partition(vector<int> &values, int left, int right);
void heapify(vector<int> &testSet, int n, int i);

// Store for sorted sets
vector<int> sortedSets[6];

// Store for number of compares
int compares;

// Store for number of swaps
int swaps;

int main() {

  string datafile;
  vector<int> dataset;

  // Almost Sorted
  cout << "Enter almost sorted dataset: ";
  cin >> datafile;
  cout << endl;

  if (datafile == "1") {datafile = "almost";}

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  if ((sortedSets[0] != sortedSets[1]) && (sortedSets[1] != sortedSets[2]) && (sortedSets[2] != sortedSets[3]) && (sortedSets[3] != sortedSets[4]) && (sortedSets[4] != sortedSets[5])) {
    cout << "Sorting error" << endl;
  }

  writeDataset(datafile);

  cout << endl;

  // Randomly Distributed
  cout << "Enter randomly distributed dataset: ";
  cin >> datafile;
  cout << endl;

  if (datafile == "1") {datafile = "random";}

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  if ((sortedSets[0] != sortedSets[1]) && (sortedSets[1] != sortedSets[2]) && (sortedSets[2] != sortedSets[3]) && (sortedSets[3] != sortedSets[4]) && (sortedSets[4] != sortedSets[5])) {
    cout << "Sorting error" << endl;
  }

  writeDataset(datafile);

  cout << endl;

  // Reverse Sorted
  cout << "Enter reverse sorted dataset: ";
  cin >> datafile;
  cout << endl;

  if (datafile == "1") {datafile = "reverse";}

  dataset = loadDataset(datafile);

  for (int x = 0; x < 6; x++){
    runTimeTest(dataset, x);
  }

  if ((sortedSets[0] != sortedSets[1]) && (sortedSets[1] != sortedSets[2]) && (sortedSets[2] != sortedSets[3]) && (sortedSets[3] != sortedSets[4]) && (sortedSets[4] != sortedSets[5])) {
    cout << "Sorting error" << endl;
  }

  writeDataset(datafile);

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

  if ((sortedSets[0] != sortedSets[1]) && (sortedSets[1] != sortedSets[2]) && (sortedSets[2] != sortedSets[3]) && (sortedSets[3] != sortedSets[4]) && (sortedSets[4] != sortedSets[5])) {
    cout << "Sorting error" << endl;
  }

  writeDataset(datafile);

  return 0;
}

vector<int> selectionSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
  compares = 0;
  swaps = 0;

  int n = testSet.size();
  int i, j, min_idx;

  for (i = 0; i < n-1; i++) {
    min_idx = i;
    for (j = i+1; j < n; j++)
    if (testSet[j] < testSet[min_idx]) {
        min_idx = j;
        compares++;
    }

    swap(testSet[min_idx], testSet[i]);
    swaps++;
  }

  return testSet;
}

vector<int> bubbleSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
  compares = 0;
  swaps = 0;

  int n = testSet.size();
  int i, j;

  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++)
      if (testSet[j] > testSet[j+1]) {
        compares++;
        swap(testSet[j], testSet[j+1]);
        swaps++;
      }
  }

  return testSet;
}

vector<int> insertionSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
  compares = 0;
  swaps = 0;

  int n = testSet.size();
  int i, key, j;

  for (i = 1; i < n; i++) {
    key = testSet[i];
    j = i - 1;

    while (j >= 0 && testSet[j] > key) {
      compares++;
      testSet[j + 1] = testSet[j];
      swaps++;
      j = j - 1;
    }
    testSet[j + 1] = key;
    swaps++;
  }

  return testSet;
}

vector<int> mergeSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
  compares = 0;
  swaps = 0;

  if (testSet.size() <= 1)
    return testSet;
  int len = testSet.size() / 2;
  vector<int> left(testSet.begin(), testSet.begin() + len);
  vector<int> right(testSet.begin() + len, testSet.end());
  return merge(mergeSort(left), mergeSort(right));
}

vector<int> quickSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
  compares = 0;
  swaps = 0;

  qs(testSet, 0, testSet.size() - 1);

  return testSet;
}

vector<int> heapSort(vector<int> &dataset) {
  vector<int> testSet = dataset;
  compares = 0;
  swaps = 0;

  int n = testSet.size();

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(testSet, n, i);

  for (int i=n-1; i>0; i--) {
    swap(testSet[0], testSet[i]);
    swaps++;

    heapify(testSet, i, 0);
  }

  return testSet;
}

vector<int> loadDataset(string datafile) {
  ifstream is(datafile);
  istream_iterator<int> start(is), end;
  vector<int> numbers(start, end);
  cout << "Read " << numbers.size() << " numbers" << endl;

  cout << "Current dataset: (" << datafile << ")\n\n";

  return numbers;
}

void writeDataset(string datafile) {
  ofstream writeFile;
  writeFile.open(datafile + "-SORTED");

  writeFile << "Selection Sort:" << endl;
  for(int i=0; i < sortedSets[0].size(); i++)
    writeFile << sortedSets[0].at(i) << ' ';
  writeFile << endl << endl;

  writeFile << "Bubble Sort:" << endl;
  for(int i=0; i < sortedSets[1].size(); i++)
    writeFile << sortedSets[1].at(i) << ' ';
  writeFile << endl << endl;

  writeFile << "Insertion Sort:" << endl;
  for(int i=0; i < sortedSets[2].size(); i++)
    writeFile << sortedSets[2].at(i) << ' ';
  writeFile << endl << endl;

  writeFile << "Merge Sort:" << endl;
  for(int i=0; i < sortedSets[3].size(); i++)
    writeFile << sortedSets[3].at(i) << ' ';
  writeFile << endl << endl;

  writeFile << "Quick Sort:" << endl;
  for(int i=0; i < sortedSets[4].size(); i++)
    writeFile << sortedSets[4].at(i) << ' ';
  writeFile << endl << endl;

  writeFile << "Heap Sort:" << endl;
  for(int i=0; i < sortedSets[5].size(); i++)
    writeFile << sortedSets[5].at(i) << ' ';
  writeFile << endl << endl;

  writeFile.close();
}

void runTimeTest(vector<int> &dataset, int algoNum) {
  using namespace std::chrono;

  string algoName;

  auto start = high_resolution_clock::now();

  if (algoNum == 0){algoName = "selection sort"; sortedSets[algoNum] = selectionSort(dataset);}
  else if (algoNum == 1){algoName = "bubble sort"; sortedSets[algoNum] = bubbleSort(dataset);}
  else if (algoNum == 2){algoName = "insertion sort"; sortedSets[algoNum] = insertionSort(dataset);}
  else if (algoNum == 3){algoName = "merge sort"; sortedSets[algoNum] = mergeSort(dataset);}
  else if (algoNum == 4){algoName = "quick sort"; sortedSets[algoNum] = quickSort(dataset);}
  else if (algoNum == 5){algoName = "heap sort"; sortedSets[algoNum] = heapSort(dataset);}

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken by " << algoName << ": " << duration.count() << " microseconds" << endl;
  cout << "Compares taken by " << algoName << ": " << to_string(compares) << " compares" << endl;
  cout << "Swaps taken by " << algoName << ": " << to_string(swaps) << " swaps" << endl << endl;;
}

vector<int> merge(vector<int> left, vector<int> right) {
	size_t ileft = 0, iright = 0;
	vector<int> results;
	while (ileft < left.size() && iright < right.size()) {
	  if (left[ileft] < right[iright])
	    results.push_back(left[ileft++]);
	  else
	    results.push_back(right[iright++]);

    compares++;
  }
	while (ileft < left.size()) {
    results.push_back(left [ileft++]);
    swaps++;
  }

	while (iright < right.size()) {
    results.push_back(right[iright++]);
    swaps++;
  }

	return results;
}

void qs(vector<int> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        qs(values, left, pivotIndex - 1);
        qs(values, pivotIndex, right);
    }
}

int partition(vector<int> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
            compares++;
        }
        while(values[j] > pivotValue) {
            j--;
            compares++;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            swaps++;
            i++;
            j--;
        }
    }
    return i;
}

void heapify(vector<int> &testSet, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && testSet[l] > testSet[largest]) {
        largest = l;
        compares++;
    }

    if (r < n && testSet[r] > testSet[largest]) {
        largest = r;
        compares++;
    }

    if (largest != i)
    {
        swap(testSet[i], testSet[largest]);
        swaps++;

        heapify(testSet, n, largest);
    }
}
