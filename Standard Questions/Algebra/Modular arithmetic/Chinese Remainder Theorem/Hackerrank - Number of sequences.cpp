/*
 * File: Hackerrank - Number of sequences
 * Algorithm: Chinese Remainder Theorem
 * Created Date: Tuesday August 4th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int mul(ll x, ll y) {
  return x * y % mod;
}

const int M = 1e6 + 10;

vector<pair<int, int>> ps[M];

bool u[M];
int n;
int rem[M];
bool good;
vector<int> primes;

void sito() {
  for (int i = 2; i < M; ++i) 
    if (!u[i]) {
      primes.push_back(i);
      for (int j = i; j < M; j += i) {
        u[j] = true;

        int x = j;
        int a = 0;
        while (x % i == 0) {
          x /= i;
          ++a;
        }

        ps[j].emplace_back(i, a);
      }
    }
}

void read() {
  cin >> n;
}

void set_rem(int x, int pw) {
    if (rem[pw] == -1)
    rem[pw] = x;

    if (rem[pw] != x)
    good = false;
}

void kill() {
    fill(rem, rem + M, -1);
    good = true;

    for (int k = 1; k <= n; ++k) {
    int x;
    cin >> x;
    if (x == -1)
        continue;

    for (auto d : ps[k]) {
        int p = d.first;
        int pw = d.second;
        int cur = p;

        for (int k = 1; k <= pw; ++k) {
        set_rem(x % cur, cur);
        cur *= p;
        }
    }
    }

    if (!good) {
    cout << "0\n";
    return;
    }

    int ans = 1;

    for (int p : primes) {
    int cur = 1, a = 0, b = 0;
    while (cur <= n / p) {
        cur *= p;
        a++;
        if (rem[cur] != -1)
        b = a;
    }

    for (int i = 0; i < a - b; ++i)
        ans = mul(ans, p);
    }

    cout << ans << endl;
}

int main() {
    sito();
    read();
    kill();
    return 0;
}