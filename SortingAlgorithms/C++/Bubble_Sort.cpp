#include <iostream>
using namespace std;

void bubble_sort(int a[],int n){
	int t;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j+1]<a[j]){
					t=a[j+1];
					a[j+1]=a[j];
					a[j]=t;
			}
		}
	}
}

 int main(){
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	int a[n];
	cout<<"Enter the elements: ";
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	bubble_sort(a,n);
	
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}   