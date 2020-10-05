/*
 * File: HackerRank - Is Fibo
 * Algorithm: Fibonacci Numbers
 * Created Date: Saturday July 25th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(long long x){ 
    long long s = sqrt(x); 
    return (s*s == x); 
} 

bool isFibonacci(long long n){ 
    return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4); 
}

int main(){
    int t;
    cin>>t;
    long long n;
    while(t--){
        cin>>n;
        if(isFibonacci(n)){
            cout<<"IsFibo"<<endl;
        }
        else{
            cout<<"IsNotFibo"<<endl;
        }
    }
    return 0;
}
