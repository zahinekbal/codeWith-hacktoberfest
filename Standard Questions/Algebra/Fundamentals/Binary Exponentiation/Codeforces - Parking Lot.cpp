/*
 * File: Codeforces - Parking Lot
 * Algorithm: Binary Exponentiation
 * Created Date: Monday July 20th 2020
 * Author: preetam rane
 */

#include <bits/stdc++.h>

using namespace std;

long long factorial(int n) { 
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); 
}

int main(){
    int n;
    cin>>n;
    cout<< (2*n-2)*factorial(n)<<endl;
    return 0;
}
