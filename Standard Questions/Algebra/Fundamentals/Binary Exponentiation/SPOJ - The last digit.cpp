/*
 * File: SPOJ - The last digit
 * Algorithm: Binary Exponentiation
 * Created Date: Tuesday July 21st 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

long long lastdigit(long long a, long long b, long long m) {
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
        long long a,b;
        cin>>a>>b;
        cout<<lastdigit(a,b,10)<<endl;
    }
    return 0;
}
