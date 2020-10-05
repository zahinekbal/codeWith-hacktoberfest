/*
 * File: UVa 11029 - Leading and Trailing
 * Algorithm: Binary Exponentiation
 * Created Date: Monday July 20th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

#define ll long long
using namespace std;
ll n, k, t;

ll bigmod(ll b, ll p, ll m){
    if(p==0)return 1;
    ll xx=bigmod(b, p/2, 1000);
    xx=(xx*xx)%1000;
    if(p%2==1)xx=(xx*b)%1000;
    return xx;
}

int main(){

    cin>>t;
    while(t--){
        cin>>n>>k;

        double x=k*(log10(n));
        x=x-(int)x;
        double ans=pow(10, x);
        ans=ans*100;
        cout<<(int)ans<<"...";

        printf("%03lld\n", bigmod(n, k, 1000));
    }
    return 0;
}
