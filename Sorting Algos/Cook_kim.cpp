#include<stdio.h>
#define SIZE 100

int arr[SIZE];

void insertion_sort(int arr[],int n);
void cook_kim_sort(int arr1[],int arr2[],int i,int j);

int main()
{
	int n;
	scanf("%d",&n);
	int i,arr1[SIZE],arr2[SIZE];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	int j=0,k=0;
	for(i=0;i<n;i++)
	{
		if(i!=n-1 && arr[i]>arr[i+1])
		{
			arr1[j++] = arr[i];
			arr1[j++] = arr[++i];
		}
		else
		{
			if(arr[i]>arr[k-1])
			arr2[k++] = arr[i];
			else
			arr1[j++] = arr[i];
		}
	}
	cook_kim_sort(arr1,arr2,j,k);
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	return 0;
}

void insertion_sort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		int temp = arr[i];
		for(j=i-1;j>=0 && arr[j]>temp;j--)
		arr[j+1] = arr[j];
		arr[j+1] = temp;
	}
}


void cook_kim_sort(int arr1[],int arr2[],int i,int j)
{
	insertion_sort(arr1,i);
	int x=0,y=0,z=0;
	while(x<i && y<j)
	{
		if(arr1[x]>arr2[y])
			arr[z++] = arr2[y++];
		else
			arr[z++] = arr1[x++];
	}
	
	if(x!=i)
	{
		while(x!=i)
		arr[z++] = arr1[x++];
	}
	
	if(y!=j)
	{
		while(y!=j)
		arr[z++] = arr2[y++];
	}
}
