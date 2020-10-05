/*
 * File: Codeforces - Power Tower
 * Algorithm: Euler's totient function
 * Created Date: Sunday August 2nd 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;

int a[maxn], md[maxn];
int n, m, w, q;

ll mul(ll a, ll b, ll p){

    return (a *= b) < p ? a : a % p + p;
}

ll qpow(ll a, ll b, ll p){

    ll ret = 1;
    while(b){

        if(b & 1) ret = mul(ret, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ret;
}

ll phi(ll x){

    ll ret = x;
    for(ll i = 2; i * i <= x; ++i){

        if(x % i) continue;
        ret = ret / i * (i - 1);
        while(x % i == 0) x /= i;
    }
    if(x > 1) ret = ret / x * (x - 1);
    return ret;
}

ll dfs(int d, int l, int r, ll p){

    if(l > r) return 1;
    if(p == 1) return 1;
    return qpow(a[l], dfs(d + 1, l + 1, r, md[d + 1]), p);
}

void init(){

    md[0] = m;
    for(int i = 0; md[i] > 1; ++i) md[i + 1] = phi(md[i]);
}

int main(){
 
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    init();
    for(int i = 1; i <= n; ++i) cin >> a[i];
    cin >> q;
    while(q--){

        int l, r; cin >> l >> r;
        ll ret = dfs(0, l, r, m) % m;
        cout << ret << "\n";
    }
    return 0;
}
