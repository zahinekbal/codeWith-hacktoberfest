/*
 * File: UVA #10179 "Irreducible Basic Fractions" [Difficulty: Easy]
 * Algorithm: Euler's totient function
 * Created Date: Friday July 31st 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


int main(){
    long long t;
    while(cin>>t && t!=0){
        cout<<phi(t)<<endl;
    }
    return 0;
}
