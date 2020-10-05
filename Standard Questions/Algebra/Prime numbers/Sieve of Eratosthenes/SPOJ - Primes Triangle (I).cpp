/*
 * File: SPOJ - Primes Triangle (I)
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Monday July 27th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;

#define mx 100000007
#define sz 14505

int a[(mx >> 5) + 2], pos[mx], tmp[sz];

bool Check(int n, int pos) {
    return (bool) (n & (1 << pos));
}

int Set(int n, int pos) {
    return n = n | (1 << pos);
}

void binary_search(int n) {
    int hi = sz - 2, lw = 1, mid;
    while (lw <= hi) {
        mid = (lw + hi) >> 1;
        if (n == tmp[mid]){ 
            hi = mid; break; 
        }
        else if (n < tmp[mid]) hi = mid - 1;
        else lw = mid + 1;
    }
    printf("%d %d\n", hi, abs(n - tmp[hi]) + 1);
}

void sieve() {
    int rt = (int) sqrt(mx);
    for (int i = 3; i <= rt; i += 2) {
        if (Check(a[i >> 5], i & 31) == 0) {
            for (int j = i * i, k = i << 1; j <= mx; j += k) {
                a[j >> 5] = Set(a[j >> 5], j & 31);
            }
        }
    }
    pos[2] = 1;
    for (int i = 3, k = 2; i <= mx; i += 2) {
        if (Check(a[i >> 5], i & 31) == 0) 
            pos[i] = k++;
    }
    for (int i = 1, j = 1; i < sz - 2; i++) 
        tmp[i] = j, j += i;
}

int main() {  
    sieve();
    int t, n, m;
    for (scanf("%d", &t); t--; ) {
        scanf("%d", &n);
        m = pos[n];
        if (m == 0) puts("-1");
        else binary_search(m);
    }
}