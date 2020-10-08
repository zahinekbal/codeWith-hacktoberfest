#include<iostream>

using namespace std;

int findSingle(int ar[], int ar_size) 
    { 
        
        int ans = ar[0]; 
        for (int i = 1; i < ar_size; i++) 
            ans = ans ^ ar[i]; 
  
        return ans; 
    } 

    int main() 
    { 
        int sizeOfTheArray ;
        cout<<"Enter the total No.of numbers in list"<<endl;
        cin >> sizeOfTheArray;

        int ar[sizeOfTheArray]; 

        cout<<"Enter the list of numbers "<<endl;

        for (int i = 0; i < sizeOfTheArray; ++i)
        {
            cin>> ar[i];
        }
         
        int n = sizeof(ar) / sizeof(ar[0]); 
        cout << "Element occurring once is  : " 
             << findSingle(ar, n); 
        return 0; 
    } 