/*
 * File: Codeforces - Lunar New Year and a Recursive Sequence
 * Algorithm: Discrete Root
 * Created Date: Friday August 7th 2020
 */

// The solution belongs to: https://www.programmersought.com/article/2762548680/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3fll
#define LL long long
#define sc(x) scanf("%lld",&x)
#define scc(x,y) scanf("%lld%lld",&x,&y)
#define sccc(x,y,z) scanf("%d%d%d",&x,&y,&z)
using namespace std;
 
const int N = 110;
const int mod = 998244353 - 1;
 
map<LL, LL> tab;
LL K,n,m,b[N];
 
struct Matrix
{
	LL a[N][N];
    Matrix(){memset(this,0,sizeof(Matrix));}
 
    Matrix operator *(const Matrix x) const
    {
        Matrix ans;
        for(int i=0;i<K;i++)
            for(int j=0;j<K;j++)
            {
                for(int k=0;k<K;k++)
                    ans.a[i][j]+=a[i][k]*x.a[k][j]%mod;
                ans.a[i][j]%=mod;
            }
        return ans;
    }
 
    friend Matrix operator ^(Matrix x,LL y)
    {
        Matrix ans;
        for(int i=0;i<K;i++)
            ans.a[i][i]=1;
        while(y)
        {
            if (y&1) ans=ans*x;
            x=x*x; y>>=1;
        }
        return ans;
    }
 
};
 
LL qpow(LL x,LL n,LL p)
{
    LL res=1;
    while(n)
    {
        if (n&1) res=res*x%p;
        x=x*x%p; n>>=1;
    }
    return res;
}
 
LL bsgs(LL a, LL b, LL p){
    LL u = (LL) sqrt(p) + 1;
    LL now = 1, step;
    for (LL i = 0; i < u; i++){
        LL tmp = b * qpow(now, p - 2, p) % p;
        if (!tab.count(tmp)){
            tab[tmp] = i;
        }
        (now *= a) %= p;
    }
    step = now;
    now = 1;
    for (LL i = 0; i < p; i += u){
        if (tab.count(now)){
            return i + tab[now];
        }
        (now *= step) %= p;
    }
    return -1;
}
 
LL ex_gcd(LL a,LL b,LL &x,LL &y)
{
if(b==0){x=1; y=0;return a;}
else
    {
        LL r=ex_gcd(b,a%b,y,x);
        y-=x*(a/b); return r;
    }
}
 
LL solve(LL a, LL b, LL c)
{
    if (c == 0) return 0;
    LL q = __gcd(a, b);
    if (c % q){
        return -1;
    }
    a /= q, b /= q, c /= q;
    LL ans, _;
    ex_gcd(a, b, ans, _);
    (ans *= c) %= b;
    while (ans < 0) ans += b;
    return ans;
}
 
int main()
{
    sc(K);
    for(int i=0;i<K;i++) sc(b[i]);
    Matrix x;
    for(int i=1;i<K;i++) x.a[i][i-1]=1;
    for(int i=0;i<K;i++) x.a[0][i]=b[i];
    scc(n,m); x=x^(n-K); LL y=bsgs(3,m,mod+1);
    LL ans=solve(x.a[0][0],mod,y);
    if (ans<0) printf("%lld\n",-1LL);
        else printf("%lld\n",qpow(3,ans,mod+1));
    return 0;
}


