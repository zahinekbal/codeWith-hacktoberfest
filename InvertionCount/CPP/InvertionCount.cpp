/**
 * Inversion Count using Merge Sort
 * Time Complexity O(n log n)
 * 
 * For each element of the array at Merge() we count the number of elements
 * greater than it on the left
 * and add it to inversionCount
*/

#include <iostream>
using namespace std;

int Merge(int arr[], int aux[], int low, int mid, int high)
{
	int k = low, i = low, j = mid + 1;
	int inversionCount = 0;

	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j]) {
			aux[k++] = arr[i++];
		}
		else {
			aux[k++] = arr[j++];
			inversionCount += (mid - i + 1);	// NOTE
		}
	}

	while (i <= mid)
		aux[k++] = arr[i++];

	for (int i = low; i <= high; i++)
		arr[i] = aux[i];

	return inversionCount;
}


int mergeSort(int arr[], int aux[], int low, int high)
{
	if (high == low)
		return 0;
	int mid = (low + ((high - low) >> 1));
	int inversionCount = 0;

	inversionCount += mergeSort(arr, aux, low, mid);
	inversionCount += mergeSort(arr, aux, mid + 1, high);
	inversionCount += Merge(arr, aux, low, mid, high);

	return inversionCount;
}

int main()
{
    int N;
    cout << "Enter the size of your array:\n";
    cin >> N;

	int arr[N];
	cout << "Enter your values into the array:\n";
	for(int i=0; i<N; i++)
	    cin >> arr[i];

	int aux[N];
	for (int i = 0; i < N; i++)
		aux[i] = arr[i];

	cout << "Inversion count is " << mergeSort(arr, aux, 0, N - 1);

	return 0;
}
