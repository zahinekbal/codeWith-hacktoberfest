/*
	BOGO SORT :: permutes everything randomly to sort the array
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int array[], int size); //Displays given array
int is_sorted(int arr[], int n); //checks if the current permuted state is sorted
void rand_shuffle(int arr[], int n); //permutes / shuffles randomly

int main()
{
	int A[5] = {4, 2, 5, 1, 3};

	clock_t begin = clock();

	while (is_sorted(A, 5) != 0)
	{
		rand_shuffle(A, 5);
		display(A, 5);
	}

	clock_t end = clock();
	
	double _time = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("TIME STAMP -------> %f\n", _time);
}

void rand_shuffle(int arr[], int n)
{
	int rand_index1 = rand()%n;
	int rand_index2 = rand()%n;

	int temp = arr[rand_index1];
	arr[rand_index1] = arr[rand_index2];
	arr[rand_index2] = temp;
}

int is_sorted(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			return -1;
		}
	}
	return 0;
}

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        (i == size - 1) ? printf("%i\n", array[i]) : printf("%i, ", array[i]);
    }
}
