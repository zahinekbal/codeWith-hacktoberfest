#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 


int equal_sum_partition(int arr[], int n) 
{ 
    int i, j,sum=0; 
    //sum whole array
    for (int i = 0; i < n; ++i)
    {
        sum=sum+arr[i];
    }

    //if sum is odd partiton not possible
    if (sum%2!=0)
    {
        cout<<"Ans= Partiton not possible"<<endl;
        return 0;
    }

    // for half sum make table and solve. if it is true other half will also be possible 
    int half_sum=sum/2;
    bool t[n + 1][half_sum + 1]; 
     // initialize top row as true  
    for (i = 0; i < half_sum+1; i++){
        t[0][i] = false;  
    }  
    // initialize leftmost column,  
    // except part[0][0], as 0  
    for (i = 1; i <= n+1; i++){
        t[i][0] = true; 
    } 

     //for understanding
    cout<<"Before DP"<<endl;
    for (i = 0; i < n+1; i++) { 
        for (j = 0; j < half_sum+1; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl;


    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < half_sum+1; ++j)
        {
            if(arr[i]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j]; 
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    // for understanding
    cout<<"After DP"<<endl;
    for (i = 0; i < n+1; i++) { 
        for (j = 0; j < half_sum+1; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl; 
    
    cout<<"Final Ans"<<endl;
    cout<<"Partition is possible"<<endl;
    return t[n][half_sum +1];

}

int main(){
	int arr[] ={ 1,5,5,11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<endl<<"EQUAL SUM PARTITION USING DYNAMIC PROGRAMMING"<<endl;
    cout<<endl<<"GIVEN"<<endl<<"arr[] = { 1,5,5,11 }"<<endl<<"n = size of arr[]= 6"<<endl<<endl;
    cout<<"STEPS:"<<endl;
    cout<<"1. Divide Sum by 2. if it is odd partition is not possible return false. Else if even it is possible."<<endl<<"2. Initialize 1st row with 0 and 1st column with 1"<<"3. Create table with size n+1 and sum/2+1 "<<endl<<"4. Start DP loop from 1st row 1st column i.e t[1][1]"<<endl;
    cout<<"5. We check if current val is less than sum/2 or not. if it is we select it and reduce the sum. Else we go to next cell"<<endl<<"5. Return the last element of the table i.e t[n][sum/2]"<<endl<<endl;
     
    equal_sum_partition(arr,n);
    
    return 0;
}