#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int>&arr){
	for(auto i:arr)
		cout<<i<<" ";
	cout<<endl;
}

vector<int> reheap(vector<int>array,int val,int n){
	int left=-1;
	int right=-1;
	if(val*2<=n){
		left=val*2;
	}
	else
	    return array;
	if((val*2+1)<=n){
		right=val*2+1;
	}
	int temp;
	if(right==-1)
	    temp=left;
	else
	    temp=(array[left]>=array[right])?left:right;
	if(array[temp]>array[n]){
		int t=array[temp];
		array[temp]=array[n];
		array[n]=t;
		reheap(array,val-1,n);
	}
	return array;
}

void heapsort(vector<int>&array_1,int n){
	int count=1;
	for(int i=n/2;i>=0;i--){
		array_1=reheap(array_1,i,n-1);
		int t=array_1[0];
		array_1[0]=array_1[n-count];
		array_1[n-count]=t;
		count++;
		print_arr(array_1);
	}
	print_arr(array_1);
}
int main(){
	int n;
	cout<<"Enter Total Number:\n";
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	// heapsort(arr,n);
	return 0;
}