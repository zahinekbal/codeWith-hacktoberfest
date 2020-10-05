/*
 * File: FIBOSUM - Fibonacci Sum
 * Algorithm: Fibonacci Numbers
 * Created Date: Friday July 24th 2020
 * Author: preetam rane
 */

#include<stdio.h>
using namespace std;

#define MOD 1000000007;

void multiply(long long F[2][2], long long M[2][2]){
  long long x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MOD;
  long long y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MOD;
  long long z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MOD;
  long long w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(long long F[2][2], long long n){
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

long long fib(long long n){
  long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}

int main(){
    int t;
    long long n, m,result;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&m);
        if(n>m){
            printf("-1");
        }
        else{
            result=(fib(m+2)-fib(n+1))%MOD;
            if (result<0){
                result+=MOD;
            }
            printf("%lld\n", result);
        }
    return 0;
}
