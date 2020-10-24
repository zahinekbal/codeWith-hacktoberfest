#include<iostream>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 


int knapsack(int W, int wt[], int val[], int n) 
{ 
    int i, j; 

    //create table with size n+1 and W+1
    int t[n + 1][W + 1]; 
  
    // Build table t[][] in bottom up manner 
    //initialize 1st row and column
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= W; j++) { 
        	// initialize 1st row and column with 0 rest with -1
            if (i == 0 || j == 0){
            	t[i][j] = 0; 
            }else{
            	t[i][j] = -1; 
            } 
        } 
    } 

    //for understanding
    cout<<endl<<"Table before using DP"<<endl;
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= W; j++) { 
            cout<<t[i][j]<<"\t"<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl;

    //
    for (int i = 1; i <= n; i++) { 
        //start from 1st row 1 column i.e t[1][1]
        for (int j = 1; j <= W; j++) { 
            if (wt[i - 1] <= j) 
            	//if we have a valid element we either selct it or reject it 
                t[i][j] = max( 
                    val[i - 1] + t[i - 1][j - wt[i - 1]], 
                    t[i - 1][j]); 
            else
            	//cannot put current object in knapsack. it is not valid
            	//value at current block equal to prev
                t[i][j] = t[i - 1][j]; 
        } 
    }

    //for understanding
    cout<<"Table after using DP"<<endl;
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= W; j++) { 
            cout<<t[i][j]<<"\t"<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl; 
    cout<<"Return the last element of the table i.e t[m][n]"<<endl;
    cout<<"Maximum Profit = ";
    
    //return the ans
    return t[n][W]; 
}

int main(){
	int val[] = { 1,4,5,7 }; 
    int wt[] = { 1,3,4,5 }; 
    int W = 7; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout<<endl<<"0/1 KNAPSACK USING DYNAMIC PROGRAMMING"<<endl;
    cout<<endl<<"GIVEN"<<endl<<"val[] = { 1,4,5,7 }"<<endl<<"wt[] = { 1,3,4,5 }"<<endl<<"W = 7"<<endl<<"n = size of val arr[]= 4"<<endl<<endl;
    cout<<"STEPS:"<<endl;
    cout<<"1. Create table with size n+1 and W+1"<<endl<<"2. Initialize 1st row and 1st column with 0"<<endl<<"3. Start DP loop from 1st row 1st column i.e t[1][1]"<<endl;
    cout<<"4. We check if we can add the current val in knapsack or not. We select the MAX of (Profit of Adding the current product and Profit without Adding)"<<endl<<"5. Return the last element of the table i.e t[m][n]"<<endl;
	cout<<knapsack(W,wt,val,n); 
}
