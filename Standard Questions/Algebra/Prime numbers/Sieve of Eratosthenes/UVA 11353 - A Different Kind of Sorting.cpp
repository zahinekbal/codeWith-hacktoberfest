/*
 * File: UVA 11353 - A Different Kind of Sorting
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Tuesday July 28th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

#define limit 2000001

using namespace std;

typedef long long LL;

struct my{
    LL index, divisor;
};

my factors[limit];

typedef bitset<limit>bsarry;

bool cmp(my a, my b){
    if(a.divisor < b.divisor){
        return true;
    }

    else if(a.divisor == b.divisor){
        return a.index < b.index;
    }

    else{
        return false;
    }
}

void fun_factors(){
    bsarry bs;

    LL i,j;

    bs.set();
    bs[0] = bs[1] = 0;

    factors[1].index = 1;
    factors[1].divisor = 1;

    for(i=2; i<limit; i++){
        if(bs[i]){
            factors[i].index=i;
            factors[i].divisor = 1;

            for(j=i*2; j<limit; j+=i){
                factors[j].index = j;
                factors[j].divisor = 1 + factors[j / i].divisor;
                bs[j] = 0;
            }
        }
    }
    sort(factors, factors+limit, cmp);
}

int main()
{
    fun_factors();
    int tc=0;
    long long n;
    while(scanf("%lld",&n) and n){
        printf("Case %d: %lld\n", ++tc, factors[n].index);
    }

    return 0;
}