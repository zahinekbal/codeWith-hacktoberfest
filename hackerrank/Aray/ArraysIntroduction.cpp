/*
	Arrays Introduction
	
	You will be given an array of  integers and you have to print the integers in the reverse order. 
	
	Sample Input

	4
	1 4 3 2
	
	Sample Output

	2 3 4 1 
  
*/

#include <iostream>

using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    for(int i=n-1;i>=0;i--){
        cout<<a[i]<<"\t";
    }

    return 0;
}