/*
 * File: SPOJ #4141 "Euler Totient Function" [Difficulty: CakeWalk]
 * Algorithm: Euler's totient function
 * Created Date: Friday July 31st 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<phi(n)<<endl;
    }
    return 0;
}
