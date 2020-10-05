/*
 * File: Codechef - GCD and LCM
 * Algorithm: Euclidean algorithm GCD
 * Created Date: Tuesday July 21st 2020
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
        cin>>a>>b;
        long long g = gcd(a,b);
        cout<<g<<" "<<(a*b)/g<<endl;
    }
    return 0;
}
