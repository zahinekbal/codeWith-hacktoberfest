/*
 * File: Hackerrank - Longest Increasing Subsequence Arrays
 * Algorithm: Modular Inverse
 * Created Date: Tuesday August 4th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

#define FFF 500010
typedef long long ll;

ll mod = 1e9+7;

ll fact[FFF], inv[FFF];

ll ext_gcd ( ll A, ll B, ll *X, ll *Y ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}


ll modInv ( ll a, ll m ) {
    ll x, y;
    ext_gcd( a, m, &x, &y );
    if ( x < 0 ){
        x += m;
    }
    return x;
}

void precal() {
    fact[0] = 1;
    inv[0] = modInv( 1, mod );

    for(ll i = 1 ; i <= FFF-1; ++i){
        fact[i] = ( fact[i-1] * i ) % mod;
        inv[i] = modInv( fact[i], mod );
    }
}

ll nck ( int n, int k ) {
    return fact[n] * inv[n-k] % mod * inv[k] % mod;
}

ll bigmod ( ll a, ll p, ll m ) {
    ll res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}


void solution() {
    int kase;
    scanf ( "%d", &kase );

    while ( kase-- ) {
        int len, n;
        scanf ( "%d %d", &len, &n );

        int limit = len - n;

        ll res = 0;
        ll nPowerX = 1;
        ll n1powerX = bigmod( n - 1, len - n, mod );
        ll invN1 = modInv( n - 1, mod );

        for(ll i = 0 ; i <= limit ; ++i){

            if ( i == limit ) n1powerX = 1;

            ll temp = nPowerX * nck( len - i - 1, n - 1 ) % mod * n1powerX % mod;

            nPowerX *= n; nPowerX %= mod;
            n1powerX *= invN1; n1powerX %= mod;

            res += temp;
            if(res>=mod)
                res-=mod;
        }

        printf ( "%lld\n", res );
    }
}



int main () {
    precal();

    solution();

    return 0;
}
