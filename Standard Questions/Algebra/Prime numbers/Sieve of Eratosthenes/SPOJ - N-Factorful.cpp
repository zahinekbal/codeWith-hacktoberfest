/*
 * File: SPOJ - N-Factorful
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Tuesday July 28th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

int divisor[1000000+10] , ANS[11][1000000+10] ;

void sieve()
{
    for(int i=2;i<=1000000;i++)
    {
        if(divisor[i]==0)
        {
            for(int j=i;j<=1000000;j+=i) 
                divisor[j]++;
        }
    }

    for(int n=0;n<=10;n++)
    {
        for(int i=1;i<=1000000;i++) 
            ANS[n][i] = ANS[n][i-1] + (bool) ( divisor[i] == n ) ;
    }
}

int main()
{
    sieve();
    int T ;
    scanf("%d",&T);
    while( T-- )
    {
        int a , b , n ;
        scanf("%d%d%d",&a,&b,&n);
        printf("%d\n",ANS[n][b]-ANS[n][a-1]);
    }
    return 0;
}
