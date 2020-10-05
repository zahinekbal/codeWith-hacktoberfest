/*
 * File: CodeChef - Inverse of a Function
 * Algorithm: Discrete Log
 * Created Date: Thursday August 6th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD=ll(1e9+7);

ll mult(ll a,ll b){
    return (a*b)%MOD;
}

ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=mult(res,a);
        a=mult(a,a);
        b>>=1;
    }
    return res;
}

const int M=998244353, I2=499122177;
string n;
int x, m;

ll bsgs(ll g, ll t, ll m) {
	ll sp=1%m, pn=64-__builtin_clzll(m);
	for(ll i=0; i<pn; ++i, sp=sp*g%m)
		if(sp==t)
			return i;
	ll d=__gcd(sp, m);
	if(__gcd(t, m)^d)
		return -1;
	ll b=1, gp=g;
	for(; b*b<m; ++b)
		gp=gp*g%m;
	unordered_map<ll, ll> mp;
	for(ll i=1, p=t*g%m; i<=b; ++i, p=p*g%m)
		mp[p]=i;
	for(ll i=1, p=sp*gp%m; i<=b; ++i, p=p*gp%m)
		if(mp.find(p)!=mp.end())
			return i*b-mp[p]+pn;
	return -1;
}

ll pm(ll b, ll p, ll m) {
	ll r=1;
	for(; p; p/=2, b=b*b%m)
		if(p&1)
			r=r*b%m;
	return r;
}

ll pm2(ll b, string p, ll m) {
	ll r=1;
	for(char c : p)
		r=pm(r, 10, m)*pm(b, c-'0', m)%m;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
        cin >> n >> x >> m;
        if(!x&&n!="1") {
            cout << 1%m << "\n";
            return 0;
        }
        ll b=(pm2(2, n, m)+m-1)%m, pc=bsgs(b, x, m);
        if(pc<0) {
            cout << "-1\n";
            return 0;
        }
        cout << pm2(2, n, M)*I2%M*(pm(2, pc, M)+M-1)%M << "\n";
    }
}