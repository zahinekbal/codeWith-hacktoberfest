/*
 * File: GYM - (J) Once Upon A Time
 * Algorithm: Extended Euclidean Algorithm
 * Created Date: Thursday July 23rd 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>
using namespace std;


auto gcd(int64_t a, int64_t b) {
    if(!b) return make_tuple(a, (int64_t)1, (int64_t)0);
    auto [d, x, y] = gcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}

signed main() {
    int64_t n, m, a, k;
    while(cin >> n >> m >> a >> k, n || m || a || k) {
        //Structured binding declaration (since C++17)
        auto [d, x, y] = gcd(m, a);
        if((k + a - n) % d) {
            cout << "Impossible\n"; 
            continue;
        }
        (x *= (k + a - n) / d) %= (a / d);
        while(m * x < (k + a - n) || x < 0) x += a / d;
        cout << n + m * x << "\n";
    }
    return 0;
}
