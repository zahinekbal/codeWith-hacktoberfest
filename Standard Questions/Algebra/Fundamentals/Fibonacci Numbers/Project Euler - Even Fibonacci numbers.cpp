/*
 * File: Project Euler - Even Fibonacci numbers
 * Algorithm: Fibonacci Numbers
 * Created Date: Saturday July 25th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

long long evenFibSum(long long limit){ 
    if (limit < 2) 
        return 0; 
 
    long long ef1 = 0, ef2 = 2; 
    long long sum = ef1 + ef2; 

    while (ef2 <= limit){ 
        long long int ef3 = 4*ef2 + ef1; 

        if (ef3 > limit) 
            break; 

        ef1 = ef2; 
        ef2 = ef3; 
        sum += ef2; 
    } 
  
    return sum; 
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        long long limit;
        cin>>limit;
        cout << evenFibSum(limit)<<"\n"; 
    }
    return 0;
}
