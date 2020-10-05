/*
 * File: SPOJ - Bazinga!
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Monday July 27th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

#define mx 11000000

const double pi = 2 * acos (0.0);

bitset <11000005> bs;
vector<long long> primes;
vector<long long> bazinga;

void sieve(){
    bs.set();
    bs[0] = 0;
    bs[1] = 0;

    for(long long i = 2; i <= mx; i++){
        if(bs[i]){
            primes.push_back(i);

            for(long long j = i * i; j <= mx; j += i){
                bs[j] = 0;
            }
        }
    }

    long long s = primes.size();

    for(long long i = 0; i < s; i++){
        for(long long j = i + 1; j < s; j++){
            long long x = primes[i] * primes[j];

            if(x >= mx){
                break;
            }

            bazinga.push_back(x);
        }
    }

    sort(bazinga.begin(), bazinga.end());
}

int main()
{

    sieve();

    int t;
    cin >> t;

    while(t--)
    {
        long long n;
        cin >> n;
        cout << bazinga[n - 1] << endl;
    }

    return 0;
}