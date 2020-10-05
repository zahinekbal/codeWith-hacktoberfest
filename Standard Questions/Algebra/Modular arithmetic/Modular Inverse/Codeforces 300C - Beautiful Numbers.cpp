/*
 * File: Codeforces 300C - Beautiful Numbers
 * Algorithm: Modular Inverse
 * Created Date: Tuesday August 4th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 1000000;
const ll INF = 1e18;
const ll mod = 1000000007;

ll fact[N + 1],ifact[N + 1];

ll bigmod ( ll a , ll n , ll mod ){
        ll res = 1;
        while (n){
                if ( n&1 ) res = (res*a)%mod;
                n>>=1;
                a*=a;
                a%=mod;
        }
        return res;
}


void factorial ( ){
    fact[0] = ifact[0] = 1;

    for ( ll i = 1 ; i<=N ; ++i ){
        fact[i] = ( i * fact[i - 1] ) % mod;
        ifact[i] = bigmod ( fact[i] , mod - 2 , mod );
    }
}

bool go ( ll n , ll a , ll b ){
    while ( n ){
        ll x = n%10;
        if(x==a or x==b){
            n/=10;
            continue;
        }
        return 0;
    }
    return 1;
}

ll nCr ( ll n , ll r ){
    ll nu = fact[n];
    ll de = ( ifact[n - r] * ifact[r] ) % mod;
    return ( nu * de ) % mod;
}


int main()
{
    factorial( );
    ll a , b , n , way = 0;
    cin >> a >> b >> n;

    for ( ll i = 0 ; i<=n ; ++i ){
        ll sum = (i*a) + ((n-i)*b);
        if ( go( sum , a , b ) ){
            way+=nCr ( n , i );
        }
        way%=mod;
    }

    cout << way << "\n";

}
