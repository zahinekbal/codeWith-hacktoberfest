/*
 * File: DMOJ - Fibonacci Sequence (Harder)
 * Algorithm: Fibonacci Numbers
 * Created Date: Saturday July 25th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

#define ull unsigned long long
#define MOD 1000000007
#define MOD1 2000000016

typedef struct {
  ull a, b;
} Matrix;

ull N, a, b, c, d;

Matrix Fib (ull n) {
    if (!n) return (Matrix) {0, 1};
    else {
        Matrix ret = Fib (n >> 1);
        a = ret.a; 
        b = ret.b;
        c = (ull) (a * (b * 2ull % MOD - a + MOD) % MOD);
        d = (ull) (a * a % MOD + b * b % MOD);
        if (!(n & 1)) return (Matrix) { c % MOD, d % MOD };
        else if (n & 1) return (Matrix) { d % MOD, c % MOD + d % MOD};
    }
    return (Matrix){0,0};
}

void read(){
    while ((N = getchar()) < '0');
    N -= '0';
    char _ = getchar();
    while (_ >= '0') {
        N = ((N << 3) + (N << 1) + _ - '0') % MOD1;
        _ = getchar();
    }
}
    
int main() {
    read();
    return !printf("%llu\n", Fib(N).a);
}