#include<stdio.h>

void merge(int arr[],int l,int k,int r)
{
	int i=l,j=k+1;
	int res[r-l+1];
	int top=0;
	while(i<=k && j<=r)
	{
		if(arr[i]>arr[j])
		{
			res[top]=arr[j];
			j++;
			top++;
		}
		else
		{
			res[top] = arr[i];
			i++;
			top++;
		}
	}
	if(i<=k)
	{
		while(i<=k)
		{
			res[top]=arr[i];
			top++;
			i++;
		}
	}
	if(j<=r)
	{
		while(j<=r)
		{
			res[top]=arr[j];
			top++;
			j++;
		}
	}
	for(i=0;i<top;i++)
	arr[l+i] = res[i];
}
void mergesort(int arr[],int l,int r)
{
	if(l>=r)
	return;
	int k = (l+r)/2;
	mergesort(arr,l,k);
	mergesort(arr,k+1,r);
	merge(arr,l,k,r);
}
int main()
{
	int n;
	printf("Enter size of array : ");
	scanf("%d",&n);
	int i,arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	for(i=0;i<n;i++)
	printf("%d  ",arr[i]);
	return 0;
}
