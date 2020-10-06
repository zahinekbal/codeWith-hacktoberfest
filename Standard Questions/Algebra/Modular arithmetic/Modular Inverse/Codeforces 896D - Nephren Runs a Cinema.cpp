/*
 * File: Codeforces 896D - Nephren Runs a Cinema
 * Algorithm: Modular Inverse
 * Created Date: Tuesday August 4th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;

int n,l,r,p;
int tot;
ll fac[maxn],inv[maxn],a[maxn],c[maxn][30];

ll qpow(ll x,ll n) {
    ll res = 1;
    while(n) {
        if(n & 1) res = res * x % p;
        n >>= 1;
        x = x * x % p;
    }
    return res;
}

void init() {
    fac[0] = inv[0] = 1;
    ll tmp = p;
    for(int i = 2;i * i <= tmp;i++) {
        if(!(tmp % i)) {
            a[++tot] = i;
            while(!(tmp % i)) tmp /= i;
        }
    }
    if(tmp > 1) a[++tot] = tmp;
    ll phi = p;
    for(int i = 1;i <= tot;i++) phi = phi / a[i] * (a[i] - 1);
    for(int i = 1;i < maxn;i++) {
        ll x = i;
        for(int j = 1;j <= tot;j++) {
            c[i][j] = c[i - 1][j];
            while(!(x % a[j])) {
                x /= a[j];c[i][j]++;
            }
        }
        fac[i] = fac[i - 1] * x % p;
        inv[i] = qpow(fac[i],phi - 1);
    }
}

ll C(ll x,ll y) {
    if(x < y) return 0;
    if(!y) return 1;
    ll res = fac[x] * inv[y] % p * inv[x - y] % p;
    for(int i = 1;i <= tot;i++) {
        res = res * qpow(a[i],c[x][i] - c[y][i] - c[x - y][i]) % p;
    }
    return res;
}

int main() {
    scanf("%d%d%d%d",&n,&p,&l,&r);
    init();
    ll ans = 0;
    for(int i=0;i<=n;i++) {
        ans = (ans + C(n,i) * (C(i,(i + l + 1) / 2) - C(i,(i + r) / 2 + 1)) % p) % p;
    }
    if(ans < 0) ans += p;
    printf("%lld\n",ans);
    return 0;
}

