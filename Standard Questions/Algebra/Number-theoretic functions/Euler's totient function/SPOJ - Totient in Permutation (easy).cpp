/*
 * File: SPOJ - Totient in Permutation (easy)
 * Algorithm: Euler's totient function
 * Created Date: Sunday August 2nd 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;

const int me = 10000025;

int T, N;
int best = me;
int cnt[10];
int p[me], phi[me], result[me], length[me];

bool smaller(int a, int b){
    long long p1 = 1LL * a * phi[b];
    long long p2 = 1LL * b * phi[a];
    if(p1 != p2){
        return p1 < p2;
    }
    return a > b;
}
bool same(int a, int b){
    for(int i = 0; i < 10; i ++){
        cnt[i] = 0;
    }
    while(a > 0){
        cnt[a % 10] ++;
        a /= 10;
    }
    while(b > 0){
        cnt[b % 10] --;
        b /= 10;
    }
    for(int i = 0; i < 10; i ++){
        if(cnt[i] != 0){
            return false;
        }
    }
    return true;
}

int main() {
    for(int i = 2; i < me; i ++){
        if(!p[i]){
            for(int j = i; j < me; j += i){
                p[j] = i;
            }
        }
    }
    for(int i = 1; i < me; i ++){
        length[i] = length[i / 10] + 1;
    }
    phi[1] = 1;
    for(int i = 2; i < me; i ++){
        result[i] = best;
        int j = i / p[i];
        if(j % p[i] == 0){
            phi[i] = phi[j] * p[i];
        }
        else{
            phi[i] = phi[j] * (p[i] - 1);
        }
        if(length[i] == length[phi[i]] && same(i, phi[i])){
            if(best == -1 || smaller(i, best)){
                best = i;
            }
        }
    }
    scanf("%d", &T);
    while(T --){
        scanf("%d", &N);
        if(result[N] == me){
            puts("No solution.");
        }
        else{
            printf("%d\n", result[N]);
        }
    }
    
    return 0;
}