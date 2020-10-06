/*
 * File: SPOJ - DIVSUM
 * Algorithm: Number of divisors & Sum of divisors
 * Created Date: Monday August 3rd 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int num;
        long long ans=0;
        scanf("%d",&num);
        if(num==1)
            printf("0\n");
        else{
            int i,t=sqrt(num);
            for(i=2;i<=t;i++){
                if(num%i==0){
                    if(i==num/i)
                        ans+=i;
                    else
                        ans+=i+num/i;
                }
            }
            ans++;
            printf("%lld\n",ans);
        }
    }
    return 0;
}