/* C Program to sort an array in ascending order using Insertion Sort 

1. Take input of random set of numbers in an array.
2. Traverse this array and insert each element of this array, to its correct position where it should actually be, by shifting the other elements if required.
3. The first element in the array is considered as sorted, even if it is an unsorted array. The array is sub-divided into two parts, the first part holds the first element of the array which is considered to be sorted and second part contains all the remaining elements of array.
4. With each iteration one element from the second part is picked and inserted into the first part of array at its correct position by shifting the existing elements if required.
5. This goes until the last element in second part of array is placed in correct position in the output array.
6. Aftr that, we have the array in sorted order.





*/
#include <stdio.h>
int main()
{
    int n, i, j, temp;
    int arr[64];
 
    printf("Enter number of elements\n");
    scanf("%d", &n);
 
    for (i = 0; i < n; i++)
    {
        printf("Enter integer no . %d :", i+1);
		scanf("%d", &arr[i]);
    }
    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
            while ( j > 0 && arr[j-1] > arr[j])
            {	        
                temp     = arr[j];
                arr[j]   = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
    }
    printf("\nSorted list in ascending order:\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
