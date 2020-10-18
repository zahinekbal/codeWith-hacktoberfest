//Author : bhavyakala
//College : Birla Institute of Technology, Mesra, Ranchi
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fr0(i,e) for(ll i=0;i<e;i++)
#define fr1(i,e) for(ll i=1;i<=e;i++)
#define frn(i,s,e) for(ll i=s;i>=e;i--)
#define fr(i,s,e) for(ll i=s;i<e;i++)
#define p(a) cout<<a<<"\n"
#define ps(a) cout<<a<<" "
#define mod 1000000007
#define MAX 100000000000000000

ll parent[1000000];
ll size[1000000];

// function to swap two variables
void swap1(ll& n1, ll& n2) {
    ll temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

// function to find parent in dsu
ll find_parent(ll v) {
  if(parent[v] ==  v) {
    return v;
  }
  return parent[v] = find_parent(parent[v]);
}

// function to perform union of two sets
void union_sets(ll a,ll b) {
  a = find_par(a);
  b = find_par(b);
  if(a!=b) {
    if(size[a]<size[b]) {
      swap1(a,b);
    }
    parent[b] = a;
    size[a]+=size[b];
  }
} 


int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);  
  #endif  
  ios::sync_with_stdio(0);  
  cin.tie(0);
  cout.tie(0);
  return 0;
}    