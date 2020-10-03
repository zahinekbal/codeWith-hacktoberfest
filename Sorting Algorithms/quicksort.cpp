#include <iostream>
#include<stdio.h> 
using namespace std;

void swapping(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot element
    int i = (low - 1);  // Index of smaller element 

    for (int j = low; j <= high- 1; j++) 
    { 
        /* If current element is smaller than or equal to pivot 
         increment index of smaller element*/
        if (arr[j] <= pivot) 
        { 
            i++;    
            swapping(&arr[i], &arr[j]); 
        } 
    } 
    swapping(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/*arr[] --> input array to be sorted, 
  low  --> Start index, 
  high  --> End index*/

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        // pi is partitioning index
        int pi = partition(arr, low, high);
        // Separately sorting the two halves of array 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

void print(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
} 

int main()
{
  int arr[] = {10, 27, 18, 19, 15, 22}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted Array:"); 
    print(arr, n); 
    return 0; 
}
