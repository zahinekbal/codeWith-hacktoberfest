#include<iostream>
using namespace std;

int k=0; 	

void sort_func(int A[],int B[],int n)    
{
	int count[k+1],t;
	for(int i=0;i<=k;i++)
	{
		count[i] = 0;
	}
	for(int i=0;i<n;i++)
	{
		t = A[i];
		count[t]++;			
	}
	for(int i=1;i<=k;i++)
	{
		count[i] = count[i]+count[i-1];            
	}
	for(int i=0;i<n;i++)
	{
		t = A[i];
		B[count[t]] = t;          
		count[t]=count[t]-1;		
	}
}
int main()
{
	int n;
	cout<<"Enter the size of the array :";
	cin>>n;	
	int A[n],B[n]; 
	cout<<"Enter the array elements: ";
	for(int i=0;i<n;i++)        
	{
		cin>>A[i];
		if(A[i]>k)
		{
			k = A[i];              
		}
	}
	
	sort_func(A,B,n);        
	
	for(int i=1;i<=n;i++)       
	{
		cout<<B[i]<<" ";
	}
	
	cout<<"\n";
	return 0;
}