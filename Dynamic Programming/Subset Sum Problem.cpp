#include<iostream>
using namespace std;

int subset_sum(int arr[], int sum, int n) 
{ 
    int i, j; 
    bool t[n + 1][sum + 1]; 
    
    for (int i = 0; i < n+1; i++) 
        t[i][0] = true; 

    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i < sum+1; i++) 
        t[0][i] = false; 
    //for understanding
    cout<<endl<<"Before DP"<<endl;
    for (i = 0; i < n+1; i++) { 
        for (j = 0; j < sum+1; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl;

    
    for (int i = 1; i < n+1; i++) { 
        for (int j = 1; j < sum+1; j++) { 
            if(arr[i-1]<=j){
                //take current value of arr and reduce the sum OR it with if it can be filled with current no and remaining sum be filled from above
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                //just use the above value from table
                t[i][j]= t[i-1][j];
            }

        } 
    }

    // for understanding
    cout<<"After DP"<<endl;
    for (i = 0; i < n+1; i++) { 
        for (j = 0; j < sum+1; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl; 
    
    cout<<"Final Ans"<<endl;
    return t[n][sum]; 
}



int main(){
    int arr[] ={ 2,3,5,6,8,10 };
    int sum = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout<<endl<<"SUBSET SUM USING DYNAMIC PROGRAMMING"<<endl;
    cout<<endl<<"GIVEN"<<endl<<"arr[] = { 2,3,5,6,8,10  }"<<endl<<"Sum = 10"<<endl<<"n = size of arr[]= 6"<<endl<<endl;
    cout<<"STEPS:"<<endl;
    cout<<"1. Create table with size n+1 and sum+1"<<endl<<"2. Initialize 1st row with 0 and 1st column with 1"<<endl<<"3. Start DP loop from 1st row 1st column i.e t[1][1]"<<endl;
    cout<<"4. We check if current val is less than sum or not. if it is we select it and reduce the sum. Else we go to next cell"<<endl<<"5. Return the last element of the table i.e t[m][n] i.e whether true or false"<<endl;
    int ans=subset_sum(arr,sum,n);
    if(ans==1){
        cout<<"It is possible";
    }
    else{
        cout<<"Not possible";
    }
    

    return 0;

}