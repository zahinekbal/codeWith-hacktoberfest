/*
 * File: SPOJ - Prime Generator
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Tuesday July 28th 2020
 * Author: preetam rane
 */
 
#include<bits/stdc++.h>
 
int N =99998953;

int status[3200000];

bool check(int N,int pos){return (bool)(N & (1<<pos));}

int Set(int N,int pos){	return N=N | (1<<pos);}

int main ()
{
     int i, j, sqrtN, n;
     sqrtN = int( sqrt( N ) );

     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( check(status[i/32],i%32)==0)
		 {
	 		 for( j = i*i; j <= N; j += 2*i )
			 {
				 status[j/32]=Set(status[j/32],j % 32);
	 		 }
		 }
	 }
	 puts("2");
	 n = 1;
	 for(i=3;i<=N;i+=2)
		 if( check(status[i/32],i%32)==0) {
         n++;
       if ( n % 500 == 1)
	 	  printf("%d\n",i);
		 }
   return 0;
}

