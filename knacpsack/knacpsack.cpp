//Author : bhavyakala
//College : Birla Institute of Technology, Mesra, Ranchi
#include<bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES
#define ll long long int
#define ld long double
#define pll pair<ll,ll>
#define pcl pair<char,ll>
#define fr0(i,e) for(ll i=0;i<e;i++)
#define fr1(i,e) for(ll i=1;i<=e;i++)
#define frn(i,s,e) for(ll i=s;i>=e;i--)
#define fr(i,s,e) for(ll i=s;i<e;i++)
#define p(a) cout<<a<<"\n"
#define ps(a) cout<<a<<" "
#define pe cout<<"\n";
#define mod 1000000007
#define MAX 100000000000000000
const ld PI = 3.14159265358979323846;

// function for solving knapsack problem
ll knapsack(ll n,ll C,ll v[],ll wt[],ll dp[][1003]) {
  if(dp[n][C]!=-1) {
    return dp[n][C];
  }
  else if(n==0 || C==0) {
    return 0;
  }
  else if (wt[n]>C){
    return knapsack(n-1,C,v,wt,dp);
  } else {
    ll t1 = knapsack(n-1,C,v,wt,dp);
    ll t2 = v[n] + knapsack(n-1,C-wt[n],v,wt,dp);
    return dp[n][C]=max(t1,t2);
  }
}