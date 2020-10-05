/*
 * File: Codechef - Golu and Sweetness
 * Algorithm: Euler's totient function
 * Created Date: Saturday August 1st 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    long long a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++){
        if(a[i]==3 or a[i]==4 or a[i]==6)
        a[i]=1;
        
        else 
        a[i]=0;
    }
    for(int i=1;i<=n-1;i++)
        a[i]+=a[i-1];

    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(l==0)
            cout<<a[r]<<"\n";

        else 
            cout<<a[r]-a[l-1]<<"\n";
    }
    return 0;
}
