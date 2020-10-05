/*
 * File: SPOJ - Namit in Trouble
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Monday July 27th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mx=100000+1;

int status[mx>>5];

vector<ll>primes;

bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int Set(int N,int pos){
    return N=N | (1<<pos);
}

void bitwise_sieve(){
    int i, j, sqrtN;
    sqrtN = int(sqrt(mx ));
    for( i = 3; i <= sqrtN; i += 2 ){
        if( Check(status[i>>5],i&31)==0){
            for( j = i*i; j <mx; j += (i<<1) ){
                status[j>>5]=Set(status[j>>5],j&31)   ;
            }
        }
    }
}

void precal(){
    primes.push_back(2ll*2ll*1ll);
    for(int i=3;i<mx;i+=2){
        if( Check(status[i>>5],i&31)==0){
            ll num=1ll*(ll)(i)*(ll)(i);
            primes.push_back(num);
        }
    }
}

int main()
{
    bitwise_sieve();
    precal();
    int tc;
    ll N,K;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld%lld", &N, &K);
        int total_choice = (int)(upper_bound(primes.begin(), primes.end(), N) - primes.begin());
        int gf_choice = total_choice - (int)(upper_bound(primes.begin(), primes.end(), K) - primes.begin());
        if(gf_choice < 0) gf_choice = 0;
        printf("%d %d\n", total_choice, gf_choice);
    }
    return 0;
}