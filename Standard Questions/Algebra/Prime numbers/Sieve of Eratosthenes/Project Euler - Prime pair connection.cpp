/*
 * File: Project Euler - Prime pair connection
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Tuesday July 28th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

#define SIEVE_RANGE (1000200)
#define PRIME_COUNT (78514)

bool sieve_visited[SIEVE_RANGE] = {};
long long prime[PRIME_COUNT] = {};
long long prime_bound[PRIME_COUNT] = {};

void Sieve(){
    int curr_pos = 0;
    long long bound = 10;
    for (long long i = 2; i < SIEVE_RANGE; i++){
        if (!sieve_visited[i]){
            prime[curr_pos] = i;
            if (i > bound){
                bound *= 10;
            }
            prime_bound[curr_pos] = bound;
            curr_pos++;
            for (long long j = i + i; j < SIEVE_RANGE; j += i){
                sieve_visited[j] = true;
            }
        }
    }
}

long long last_x, last_y;
long long x, y, t, quotient;

void ExtendedGCD(long long a, long long b){
    x = 0;
    y = 1;
    last_x = 1;
    last_y = 0;
    while (b){
        quotient = a/b;
        t = a;
        a = b;
        b = t % b;

        t = x;
        x = last_x - quotient*x;
        last_x = t;
        
        t = y;
        y = last_y - quotient*y;
        last_y = t;
    }
}


long long GetConnection(int which_p1, int which_p2){
    long long bound = prime_bound[which_p1];
    long long p1 = prime[which_p1];
    long long p2 = prime[which_p2];
    ExtendedGCD(bound, p2);
    long long rv = (-last_x * p1 ) % p2;
    if (rv <= 0)
    {
        rv += p2;
    }
    return rv * bound + p1;
}

void Solve(long long r){
    long long sum = 0;
    for (int i = 2; prime[i] <= r; i++){
        sum += GetConnection(i, i+1);
    }
    cout << sum << endl;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        Sieve();
        Solve(r);
    }
    return 0;
}
