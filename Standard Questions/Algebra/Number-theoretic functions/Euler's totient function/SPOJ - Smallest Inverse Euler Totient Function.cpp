/*
 * File: SPOJ - Smallest Inverse Euler Totient Function
 * Algorithm: Euler's totient function
 * Created Date: Sunday August 2nd 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;

const int mx=160180001;
unsigned phi[mx];
unsigned ans[mx];

void totient_sieve(){
    for(int i=1;i<mx;i++){
        phi[i]=i;
    }
    for(int p=2;p<mx;p++){
        if(phi[p]==p){
            phi[p]=p-1;
            for(int i=2*p;i<mx;i=i+p){
                phi[i]=(phi[i]/p)*(p-1);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    totient_sieve();
    for(int i=0;i<mx;i++){
        if(ans[phi[i]]==0){
            ans[phi[i]]=i;
        }
        else{
            ans[phi[i]]=min((int)ans[phi[i]],i);
        }
    }
    ans[1]=1;
    int tc,n;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        if(ans[n]==0) cout<<"-1"<<endl;
        else cout<<ans[n]<<endl;
    }
    return 0;
}