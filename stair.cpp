
//DP solution to staircase problem Time Complexity : O(n)

#include <iostream>
using namespace std;

typedef long long ll;

const int size = 1e6;
ll dp[size];

ll noofWays( int n){

    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    
    
    
    cout<<noofWays(n)<<"\n";


    
    return 0;
}
