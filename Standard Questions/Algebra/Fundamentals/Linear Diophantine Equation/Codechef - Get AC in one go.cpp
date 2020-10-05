/*
 * File: Codechef - Get AC in one go
 * Algorithm: Linear Diophantine Equation
 * Created Date: Thursday July 23rd 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

long long gcd (long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        scanf("%lld",&a);
        scanf("%lld",&b);
        if(gcd(a,b)==1){
            cout<<a*b-a-b+1;
            cout<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}
