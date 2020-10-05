#include <stdio.h>

void swap(int *a, int *b) {
    int *temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = left
    }
    if (i != largest) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    int i;
    for (i = (n / 2) - 1; i > 0; i--) {
        heapify(A, n, i);
        for (i = n - 1; i > 0; i--) {
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }
    }
}

int main() {
    n = 5;
    arr[5] = {2, 45, 87, 34, 56};
    heap_sort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d\t");
}