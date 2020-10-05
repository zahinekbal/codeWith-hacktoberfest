/*
 * File: LOJ - Mathematically Hard
 * Algorithm: Euler's totient function
 * Created Date: Sunday August 2nd 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long int

ll phi[5000009];
vector<ll>v;

void sieve(){
    for(ll i=1;i<=5000001;i++)phi[i]=i;
        for(ll i=2;i<=5000001;i++){
                if(phi[i]==i)
            for(ll j=i;j<=5000001;j+=i)
                phi[j]-=phi[j]/i;
    }

    for(ll i=2;i<=5000000;i++){
        ll temp=phi[i];
        phi[i]*=temp;
        phi[i]+=phi[i-1];
    }

}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    ll t,cs=0;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        cout<<"Case "<<++cs<<": "<<phi[m]-phi[n-1]<<"\n";
    }
    return 0;
}
