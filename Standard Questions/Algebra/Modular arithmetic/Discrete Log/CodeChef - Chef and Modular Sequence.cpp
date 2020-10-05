/*
 * File: CodeChef - Chef and Modular Sequence
 * Algorithm: Discrete Log
 * Created Date: Thursday August 6th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>
using namespace std;

const int md=100000007,sq=10001,sqn=100,sqm=1000001,root=5;

const int p[3]={2,491,101833};
int t,x,y,mn,i,j,k,lst,g,mdg,phi,v[md],dlog[sq+5];
long long invk,ans,cur,pw[sqn+5];

long long pwr(long long a, int b, int md) {
  if (b==0) return 1LL%md;
  if (b&1) return (pwr(a,b-1,md)*a)%md;
  long long x=pwr(a,b/2,md);
  return (x*x)%md;
}

int gcd(int a, int b){ 
    return b?gcd(b,a%b):a;
}

int solve(int i) {
  int cur=i,y=md;
  for (int j=0; j<=sqn; j++) {
    if (v[cur]>j) y=min(y,v[cur]-j);
    cur=(cur*root)%md;
  }
  return y;
}

int main() {
    for (pw[0]=j=1; j<=sqn; j++) pw[j]=(pw[j-1]*root)%md;

    for (cur=pw[sqn], j=1; j<=sqm; j++) {
        if (v[cur]==0) v[cur]=j*sqn;
        cur=(cur*pw[sqn])%md;
    }

    for (i=1; i<=sq; i++) 
        dlog[i]=solve(i);

    scanf("%d",&t);

    while (t--) {
        scanf("%d",&x);
        mn=md; ans=0;
        for (cur=j=1; mn>sq; j++) {
            cur=(cur*x)%md;
            if (cur<mn) {
            mn=cur;
            ans+=mn;
            }
        }

        if (mn==1) { 
            printf("%lld\n",ans); 
            continue; 
        }

        ++ans;
        k=solve(x);

        g=gcd(k,md-1);
        mdg=(md-1)/g;

        phi=mdg;
        for (i=0; i<3; i++) if (mdg%p[i]==0) phi-=phi/p[i];
        invk=pwr(k/g,phi-1,mdg);

        lst=md;
        for (i=2; i<mn; i++) {
            if (dlog[i]%g) continue;

            y=((dlog[i]/g)*invk)%mdg;

            if (y<lst) {
            ans+=i;
            lst=y;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

