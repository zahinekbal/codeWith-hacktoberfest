     #include <iostream>
     #include<stdio.h> 
        #include <bits/stdc++.h> 
        #include <cmath>
        #include <vector>
        #include <map>
        #include <string>
        #include <algorithm>
        #include <iomanip>
        #include<utility>
        using namespace std;
#define ll long long
#define len length()
#define pi pair<int,int>
#define vpi vector<pair<int,int>>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define p5 100005
#define fr(i,n) for(ll i=0;i<n;i++)
ll max(ll i,ll j){
    return i>j?i:j;
}
ll min(ll i,ll j){
    return i<j?i:j;
}
 
int hcf(int a,int b){
    if(b==0) return a;
    return hcf(b,a%b);
}
 
int ncr( int n,int r){
    if(r==0) return 1;
    if(n==r) return 1;
    if(r==1) return n;
    
    return ncr(n-1,r)+ncr(n-1,r-1);
}
 
bool isPrime(ll n){
    if(n%2==0) return false;
    for(ll i=3;i*i<=n;i+=2){
        if(n%i==0) return false;
    }
    return true;
}
bool sortValD(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}
vector<int> sieve(int n) 
{ 
    vector<bool> prime(n+1,true); 
  
    for (int p=2; p*p<=n; p++) 
    { 
       
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    vector<int> v;
    for(int i=2;i<prime.size()+2;i++){
        if(prime[i]) v.pb(i);
    }
  
 return v;
} 



int main(){
    
int t; 
//t=1;
cin>>t;    

while(t--){




ll x,y,z,a=-1,b=-1,c=-1;

cin>>x>>y>>z;

ll mx=max(x,max(y,z));

if(mx==x && mx==y) a=mx;
else if(mx==y && mx==z) c=mx;
else if(mx==x && mx==z) b=mx;
else{ cout<<"NO"<<endl; continue; }

if(a==mx){
    b=z; c=z;
}
else if(b==mx){
    a=y; c=y;
}
else{
    a=x; b=x;
}

cout<<"YES"<<endl;
cout<<a<<" "<<b<<" "<<c<<endl;

}

}
