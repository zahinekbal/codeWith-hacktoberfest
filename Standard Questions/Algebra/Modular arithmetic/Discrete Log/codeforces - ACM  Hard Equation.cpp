/*
 * File: codeforces - ACM  Hard Equation
 * Algorithm: Discrete Log
 * Created Date: Thursday August 6th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;
const int MAX=5e5+10;
typedef long long ll;

ll BSGS(ll a,ll b,ll m){
    a%=m;
    b%=m;
    if(b==1)return 0;
    unordered_map<ll,ll>ma;
    ll n=sqrt(2*m)+1;
    ll e=1;
    for(int i=0;i<n;i++)
    {
        if(ma.count(b*e%m)==0)ma[b*e%m]=i;
        e=e*a%m;
    }
    ll t=1;
    for(int i=1;i<=n+1;i++)
    {
        t=t*e%m;
        if(ma.count(t))return i*n-ma[t];
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,m;
        scanf("%lld%lld%lld",&a,&b,&m);
        printf("%lld\n",BSGS(a,b,m));
    }
    return 0;
}