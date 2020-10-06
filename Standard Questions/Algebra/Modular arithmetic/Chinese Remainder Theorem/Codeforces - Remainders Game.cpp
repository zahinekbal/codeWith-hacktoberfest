/*
 * File: Codeforces - Remainders Game
 * Algorithm: Chinese Remainder Theorem
 * Created Date: Wednesday August 5th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;
 
typedef long long LL;
 
LL n, k;
 
LL gcd(LL a, LL b) { 
    return b == 0 ? a : gcd(b, a%b); 
}

LL lcm(LL a, LL b) { 
    return a*b / gcd(a, b);
}
 
int main() {
    scanf("%lld%lld", &n, &k);
    LL lcm_ci = 1;
    bool su = 0;
    for (int i = 1; i <= n; i++) {
        LL x;
        scanf("%lld", &x);
        lcm_ci = lcm(lcm_ci, x);
        lcm_ci = gcd(k, lcm_ci);
        if (lcm_ci == k) {
            su = 1; 
            break;
        }
    }
    if (su) puts("Yes");
    else puts("No");
    return 0;
}


