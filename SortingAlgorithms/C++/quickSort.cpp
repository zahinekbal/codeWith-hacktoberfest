#include<iostream>
#include<functional>
using namespace std;

int Partition(int *a,int start,int end)
{
	int pivot=a[end];
	int pIndex=start;

	for(int i=start;i<end;i++)
	{
		if(a[i]<pivot)
		{
			if(pIndex!=i)
				swap(a[i],a[pIndex]);
			pIndex=pIndex+1;
		}
	}

	swap(a[pIndex],a[end]);
	return pIndex;

	
}

void Quicksort(int *a,int start,int end)
{

	if(start<end)
	{
		int pIndex=Partition(a,start,end);
		Quicksort(a,start,pIndex-1);
		Quicksort(a,pIndex+1,end);
	}
 
}

int main()
{
	int a[]={7,3,9,1,5,2};
	int n=sizeof(a)/sizeof(a[0]);

	Quicksort(a,0,n-1);

	for(int i=0;i<n;i++)
		cout << a[i] <<" ";

	return 0;
}