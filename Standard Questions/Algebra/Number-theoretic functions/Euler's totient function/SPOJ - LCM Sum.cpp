/*
 * File: SPOJ - LCM Sum
 * Algorithm: Euler's totient function
 * Created Date: Saturday August 1st 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
 
ll res[1000010];
ll phi[1000010];
 
void precal( int n ) {
    for(ll i = 1 ; i <= n ; ++i) phi[i] = i;
    for(ll i = 2 ; i <= n ; ++i) {
        if ( phi[i] == i ) {
        for ( int j = i; j <= n; j += i ) {
            phi[j] /= i;
            phi[j] *= i - 1;
        }
    }
 }
 for(ll i = 1 ; i <= n ; ++i){
    for ( int j = i; j <= n; j += i ) {
        res[j] += ( i * phi[i] );
    }
 }
}
 
int main () {
    precal( 1000000 );
 
    int t;
    scanf ( "%d",&t );
 
    while ( t-- ) {
        ll n;
        scanf ( "%lld", &n );
        ll ans = res[n] + 1;
        ans *= n;
        ans /= 2;
 
        printf ( "%lld\n", ans );
    }
 
    return 0;
}