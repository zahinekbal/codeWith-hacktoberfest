/*
 * File: Codeforces - Nodbach Problem
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Wednesday July 29th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;

int main()
{
        long long i,j,k;
        long long n,p;

        cin>>n>>k;
        long long a[n+1];

        for(i=0;i<=n;i++){
            a[i]=1;
        }

        a[0]=0;a[1]=0;a[2]=1;
        for(i=4;i<=n;i+=2){
            a[i]=0;
        }

        for(i=3;i<=n;i+=2){
            if(a[i]==1){
                int x=2;
                while(i*x<=n){
                    a[i*x]=0;
                    x++;
                }
            }
        }

        vector<long long> v;
        for(i=0;i<=n;i++){
            if(a[i]==1)
                v.push_back(i);
        }

        int count=0;
        for(i=0;i<(v.size());i++){
            for(j=0;j<v.size();j++){
                if(v[j]+v[j+1]+1==v[i]){
                    count++;
                    break;
                }
            }
        }

        if(count>=k)
            cout<<"YES";
        else
            cout<<"NO";

        return 0;
}