#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[min_idx] > arr[j])
            min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {2, 1, 3, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
