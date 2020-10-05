/*
 * File: SPOJ - Prime or Not
 * Algorithm: Primality tests
 * Created Date: Wednesday July 29th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

ll mulmod(ll a,ll b,ll c)
{
    ll x = 0 , y = a%c ;
    while(b>0)
    {
        if(b%2) x = (x+y)%c ;
        y=(y*2)%c;
        b/=2;
    }
    return x%c ;
}

ll modulo(ll a,ll b,ll c)
{
    ll x = 1 , y = a%c ;
    while( b > 0 )
    {
        if(b%2) x = mulmod(x,y,c) ;
        y=mulmod(y,y,c);
        b/=2;
    }
    return x%c ;
}

bool miller_rabin(ll p, ll iteration)
{
    if(p<2) return false ;
    if(p%2==0&&p!=2) return false ;

    ll s = p-1 ;
    while(s%2==0) s/=2;

    for(ll i=1;i<=iteration;i++)
    {
        ll a = rand() % (p-1)+1 , temp = s ;

        ll mod = modulo(a,temp,p);
        while(mod!=1&&mod!=p-1&&temp!=p-1)
        {
            mod = mulmod(mod,mod,p);
            temp*=2;
        }
        if(temp%2==0&&mod!=p-1) return false ;
    }
    return true ;
}
int main()
{
    int T ;
    scanf("%d",&T);
    while( T-- )
    {
        ll n ;
        scanf("%lld",&n);

        if(miller_rabin(n,50)) puts("YES");
        else puts("NO");
    }
    return 0 ;
}