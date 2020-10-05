/*
 * File: UVa 374 - Big Mod
 * Algorithm: Binary Exponentiation
 * Created Date: Monday July 20th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

long long BigMOD(long long a, long long b, long long m) {
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
    long long a,b,m;
    
    while(cin>>a>>b>>m){
        cout<<BigMOD(a,b,m)<<endl;
    }
    return 0;
}
