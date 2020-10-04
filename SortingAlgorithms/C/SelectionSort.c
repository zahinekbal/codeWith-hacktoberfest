#include <stdio.h>

void acceptArray(int arr[100], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Value at position %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
}

void printArray(int arr[100], int n) {
    int j;
    for (j = 0; j < n; j++) {
        printf("%d\t", arr[j]);
    }
    printf("\n");
}

void selection_sort(int arr[100], int n) {
    int min_pos, temp;
    for (int i = 0; i < n - 1; i++) {
        min_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_pos]) {
                min_pos = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_pos];
        arr[min_pos] = temp;
    }

    printArray(arr, n);
}

int main() {
    int A[100], n;
    printf("How many elements in the array?\n");
    scanf("%d", &n);
    acceptArray(A, n);
    printArray(A, n);
    selection_sort(A, n);
}