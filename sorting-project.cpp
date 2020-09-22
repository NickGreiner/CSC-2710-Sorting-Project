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

#include<stdio>
#include<stdlib.h>
#include<vector>

using namespace std;

void selectionSort(vector<int> &dataset);
void bubbleSort(vector<int> &dataset);
void insertionSort(vector<int> &dataset);
void mergeSort(vector<int> &dataset);
void quickSort(vector<int> &dataset);
void heapSort(vector<int> &dataset);

void loadDataset(vector<int> &dataset);

int main() {

}
