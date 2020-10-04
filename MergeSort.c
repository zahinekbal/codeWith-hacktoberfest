/*
MERGE SORT: Divide array in halves and sort each half then merge
*/

#include <stdio.h>
#include <time.h>

void mergeSort(int arr[], int n); //Recursive loop for sorting
void merge(int l[], int nl, int r[], int nr, int res[]); //Main sorting logic
void copy(int arr1[], int arr2[], int start, int end); //Copies a part of arr2 into arr1
void display(int arr[], int n); //Displays given array

int main()
{
	const int n = 10;
	
	int A[n] = {1, 5, 3, 2, 4, 7, 0, 6, 9, 8};

	clock_t begin = clock();
	
	mergeSort(A, n);
	
	clock_t end = clock();

	double time = (double)(end - begin)/CLOCKS_PER_SEC;

	display(A, n);
	printf("TIME STAMP -------> %f\n", time);
}

void mergeSort(int arr[], int n)
{

	int n1 = (n + (n % 2)) / 2;
	int n2 = (n - (n % 2)) / 2;

	int arr1[n1];
	int arr2[n2];

	copy(arr1, arr, 0, n1);
	copy(arr2, arr, n - n2, n);

	if (n1 == 1 && n2 == 1)
	{
		merge(arr1, n1, arr2, n2, arr);
	}


	if (n1 != 1)
	{
		mergeSort(arr1, n1);
		mergeSort(arr2, n2);
		merge(arr1, n1, arr2, n2, arr);
	}
}

void merge(int l[], int nl, int r[], int nr, int res[])
{
	int i = 0, j = 0, k = 0;
	while (i < nl && j < nr)
	{
		if (l[i] <= r[j])
		{
			res[k] = l[i];
			i++, k++;
		}
		else
		{
			res[k] = r[j];
			j++, k++;
		}
	}
	while (i < nl)
	{
		res[k] = l[i];
		i++;
		k++;
	}
	while (j < nr)
	{
		res[k] = r[j];
		j++;
		k++;
	}
}

void display(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		(i != n - 1) ? printf("%i, ", arr[i]) : printf("%i\n", arr[i]);
	}
}

void copy(int arr1[], int arr2[], int start, int end)
{
	for (int i = start; i < end; i++)
	{
		arr1[i - start] = arr2[i];
	}
}
