/*
 * File: GCPC 15 - Divisions
 * Algorithm: Integer factorization
 * Created Date: Thursday July 30th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, a[1000006], iN, N, t1[4 * 1000006];

inline ll Mult(ll x, ll y, ll md){
    ll res = 0;
    while (y){
        if (y & 1) res = (res + x) % md, y--;
        x = (x + x) % md, y >>= 1;
    }
    return res % md;
}

inline ll Pw(ll x, ll y, ll md){
    ll res = 1;
    while (y){
        if (y & 1) res = Mult(res, x, md), y--;
        y >>= 1, x = Mult(x, x, md);
    }
    return res % md;
}

inline ll isP(ll x){
    if (x == 2) return 1;
    for (int i = 1; i <= 100; i++){
        ll a = (rand() % (x - 2)) + 2;
        if (__gcd(a, x) != 1) return 0;
        if (Pw(a, x - 1, x) != 1) return 0;
    }
    return 1;
}

void input(){
	while(cin>>a[++iN]);
	N = iN;
	n = a[1];
}

void output(){
	while(--iN)cout<<a[N - iN]<<' ';
}

int main(){




	srand(time(0));

	input();

	ll ans = 1,cnt = 1;

	for(ll i = 2; i * i * i <= n; ++i){
		while(n%i==0)n/=i,++cnt;
		if(cnt > 1)ans *= cnt,cnt=1;
	}

	if(isP(n))cout << ans * 2,exit(0);
	if(sqrt(n) * sqrt(n) == n && n > 1)cout << ans * 3,exit(0);
	if(n > 1)cout << ans * 4,exit(0);
	cout << ans;

	return 0;
}