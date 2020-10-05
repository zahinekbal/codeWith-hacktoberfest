//program in STL CPP to sort numbers in descending order using comparators.
#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{
	return a>b;//to sort in decreasing order
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n,compare);
	//to print sorted array
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
