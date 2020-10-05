/*
 * File: UVa 1230 - MODEX
 * Algorithm: Binary Exponentiation
 * Created Date: Monday July 20th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y,m;
        cin>>x>>y>>m;
        cout<<binpow(x,y,m)<<endl;
    }
    return 0;
}
