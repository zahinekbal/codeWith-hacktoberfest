//generalization of sorting by exchange (bubble sort) or sorting by insertion (insertion sort)
//an implementation of Shellsort is present in the Linux kernel

#include<stdio.h>
#define SIZE 100

void shell_sort(int arr[],int n);

int main()
{
	int n;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	int i,arr[SIZE];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	shell_sort(arr,n);
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	return 0;
}

void shell_sort(int arr[],int n)
{
	int g,i,j;
	for(g=n/2;g>0;g/=2)
	{
		for(i=g;i<n;i++)
		{
			int temp = arr[i];
			for(j=i;j>=g && arr[j-g]>temp;j-=g)
			arr[j] = arr[j-g];
			
			arr[j] = temp
			
			;
		}
	}
}
