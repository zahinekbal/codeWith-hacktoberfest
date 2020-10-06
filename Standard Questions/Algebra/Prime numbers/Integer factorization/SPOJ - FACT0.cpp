/*
 * File: SPOJ - FACT0
 * Algorithm: Integer factorization
 * Created Date: Wednesday July 29th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1000005;

int main()
{
    ll n;
    while(cin >> n){
        if(!n)
            break;
            
        ll cnt = 0;
        while(n%2 == 0){
            cnt++;
            n /= 2;
        }
        if(cnt > 0) cout << "2^"<<cnt<< " ";
        ll x = 3;
        while(x*x <= n){
            cnt = 0;
            while(n%x == 0){
                cnt++;
                n /= x;
        }
        if(cnt > 0) cout << x << "^"<<cnt<< " ";
        x += 2;
     }
     if(n > 1)cout << n << "^1\n";
   }
    return 0;
}