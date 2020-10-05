/*
 * File: 10104 - Euclid Problem
 * Algorithm: Extended Euclidean Algorithm
 * Created Date: Wednesday July 22nd 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

long long x, y, d;

void extended_Euclid(long long a, long long b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extended_Euclid(b, a % b);
    long long x1 = y, y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){
    long long A, B;
    while (cin>>A>>B) {
        extended_Euclid(A, B);         
        cout<<x<<" "<<y<<" "<<d<<endl;
    }
    return 0;
}
