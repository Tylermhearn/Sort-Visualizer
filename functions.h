#pragma once
#include <iostream>
#include <Windows.h>
#include "functions.h"
#include <gdiplus.h>
#include <thread>
#include <chrono>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void menu();
void line_creation(int num_lines);
void line_display();
void merge(std::vector<int> &arr, int, int, int);
void merge_sort(std::vector<int> &arr, int low, int high);
void quickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);
void swap(int* a, int* b);
void countSort(std::vector<int>& arr, int n, int exp);
int getMax(std::vector<int>& arr, int n);
void radixsort(std::vector<int>& arr, int n);
int shellSort(std::vector<int>& arr, int n);
void CocktailSort(std::vector<int>& a, int n);


struct line {
	int length;
};


std::vector<int> lines;


void menu() {
	std::cout << "Please select a sorting algorithm\n";
	std::cout << "A.\tBubble Sort\n";
	std::cout << "B.\tInsertion Sort\n";
	std::cout << "C.\tMerge Sort\n";
    std::cout << "D.\tQuick Sort\n";
    std::cout << "E.\tRadix Sort\n";
    std::cout << "F.\tShell Sort\n";
    std::cout << "G.\tCocktail Sort\n";
	std::cout << "X.\tEXIT\n";
	std::cout << "Y.\tCLEAR\n>> ";
}

void line_creation(int num_lines) {
	srand(time(NULL));
	for (int i = 0; i < num_lines; i++) {
		lines.push_back(rand() % 25 + 1);
	}
}

void line_display() {
	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines[i]; j++) {
			std::cout << "-";
		}
		std::cout << '\n';
	}
}


void merge_sort(std::vector<int> &arr, int low, int high)
{

	int mid;

	if (low < high) {

		//divide the array at mid and sort independently using merge sort

		mid = (low + high) / 2;

		merge_sort(arr, low, mid);

		merge_sort(arr, mid + 1, high);

		//merge or conquer sorted arrays

		merge(arr, low, high, mid);

	}

}
void merge(std::vector<int> &arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
            system("CLS");
            line_display();
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
            system("CLS");
            line_display();
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
        system("CLS");
        line_display();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
        system("CLS");
        line_display();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
        system("CLS");
        line_display();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
}

void swap(int* a, int* b)
{
    system("CLS");
    line_display();
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    int t = *a;
    *a = *b;
    *b = t;
    system("CLS");
    line_display();
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);
        system("CLS");
        line_display();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
        quickSort(arr, pi + 1, high);
        system("CLS");
        line_display();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));

    }
}



void countSort(std::vector<int>& arr, int n, int exp) {
    int output[100]; // output array 
    int i, count[10] = { 0 };

    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;

    }

    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        system("CLS");
        line_display();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
        
}
int getMax(std::vector<int>& arr, int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    
    return mx;
}
void radixsort(std::vector<int>& arr, int n) {
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
        
    }
       
}

int shellSort(std::vector<int> &arr, int n)
{
    // Start with a big gap, then reduce the gap 
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            system("CLS");
            line_display();
            std::this_thread::sleep_for(std::chrono::milliseconds(25));

            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp;
            system("CLS");
            line_display();
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
    }
    return 0;
}


void CocktailSort(std::vector<int> &a, int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // reset the swapped flag on entering 
        // the loop, because it might be true from 
        // a previous iteration. 
        swapped = false;

        // loop from left to right same as 
        // the bubble sort 
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                system("CLS");
                line_display();
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted. 
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it 
        // can be used in the next stage 
        swapped = false;

        // move the end point back by one, because 
        // item at the end is in its rightful spot 
        --end;

        // from right to left, doing the 
        // same comparison as in the previous stage 
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                system("CLS");
                line_display();
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
                swapped = true;
            }
        }

        // increase the starting point, because 
        // the last stage would have moved the next 
        // smallest number to its rightful spot. 
        ++start;
    }
}