/*
 * File: Sieve of Eratosthenes
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Saturday July 25th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;

bool Check(int N,int pos){ 
    return (bool)(N & (1<<pos));
}

void Set(int &N,int pos){ 
    N=N | (1<<pos);
}

const int MAX = 99998953;
int prime[(MAX>>5)+100];

void sieve(){
    int lim = sqrt(MAX);
    for(int i=3; i<=lim; i+=2){
        if(!Check(prime[i>>5],i&31)){
            for(int j=i*i; j<=MAX; j+=(i<<1)){
                Set(prime[j>>5],j&31);
            }
        }
    }
    cout << 2 << endl;
    int n = 1;
    for(int i=3; i<=MAX; i+=2){
        if(!Check(prime[i>>5],i&31)){
            n++;
            if(n%100 == 1)
                cout << i << endl;
        }
    }
}
int main()
{
    sieve();
}
