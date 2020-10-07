//For each column we will traverse the row in top to down or down to top direction
//In case Column is Even We will traverse Top to Bottom
// If the Column is Odd We will go Bottom to Top.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[1000][1000] = {0};
    int m,n;
    cin>>m>>n;
    //Iterate over the array
    int val=1;
    for(int row=0; row<=m-1; row++){
        for(int col=0; col<=n-1; col++){
            a[row][col] = val;
            val++;
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    //Wave print we will fix col=0 and row will traverse. Outer loop will be column and inner loop will be row.
    for(int col=0; col<n; col++){
        if(col%2 == 0){
            //Even Col -Top Down
            for(int row=0; row<m; row++){
                cout<<a[row][col]<<" ";
            }
        }
        else{
            //Bottom up Direction
            for(int row=m-1; row>=0; row--){
                cout<<a[row][col]<<" ";
            }
        }
    }
    return 0;
}

Input:-                        Output:-

3  4                        1  5  9  10  6  2  3  7  11  12   8  4

1  2  3  4
5  6  7  8
9 10 11 12

