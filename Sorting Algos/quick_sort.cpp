#include<stdio.h>

int partition(int arr[],int l,int u)
{
	int i=l,j=u+1,temp;
	do{
		do{
			i++;
		}while(i<=u && arr[i]<arr[l]);
		
		do{
			j--;
		}while(arr[j]>arr[l]);
		
		if(j>i)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}while(j>i);
	temp = arr[l];
	arr[l] = arr[j];
	arr[j] = temp;
	return j;
}
void quick_sort(int arr[],int l,int u)
{
	if(l>=u)
	return;
	int k = partition(arr,l,u);
	quick_sort(arr,l,k-1);
	quick_sort(arr,k+1,u);
}
int main()
{
	int n;
	printf("Enter size of array : ");
	scanf("%d",&n);
	int i,arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	quick_sort(arr,0,n-1);
	for(i=0;i<n;i++)
	printf("%d  ",arr[i]);
	return 0;
}
