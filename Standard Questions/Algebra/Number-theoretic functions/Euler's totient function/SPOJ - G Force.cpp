/*
 * File: SPOJ - G Force
 * Algorithm: Euler's totient function
 * Created Date: Sunday August 2nd 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000001
#define MOD 1000000007

typedef long long ll;

bool prime[MAXN];
 vector<ll> countprimes(MAXN);
 void SieveOfEratosthenes(ll n)
 {
 	memset(prime, true, sizeof(prime));
 	for (ll p = 2; p * p <= n; p++)
 	{
 		if (prime[p] == true)
 		{
 			for (ll i = p * p; i <= n; i += p)
 				prime[i] = false;
 		}
 	}
 	for (ll i = 2; i <= n; i++)
 	{
 		if (prime[i])
 			countprimes[i]++;
 		countprimes[i] += countprimes[i - 1];
 	}
 }
 vector<ll> phi(MAXN);
 void phi_1_to_n(ll n) {

 	phi[0] = 0;
 	phi[1] = 1;
 	for (ll i = 2; i <= n; i++)
 		phi[i] = i;

 	for (ll i = 2; i <= n; i++) {
 		if (phi[i] == i) {
 			for (ll j = i; j <= n; j += i)
 				phi[j] -= phi[j] / i;
 		}
 	}
 }
 ll binexp(ll a, ll b, ll m) {
 	a %= m;
 	ll res = 1;
 	while (b > 0) {
 		if (b & 1)
 			res = res * a % m;
 		a = a * a % m;
 		b >>= 1;
 	}
 	return res;
 }
 vector<ll> fact(MAXN, 1);
 void factcalc(ll n)
 {
 	for(ll i=2;i<=n;i++)
 	{
 		fact[i] = (fact[i - 1] * i) % (MOD - 1);
 	}
 }
 signed main() {
 	phi_1_to_n(MAXN - 1);
 	SieveOfEratosthenes(MAXN - 1);
 	factcalc(MAXN - 1);
 	ll t;
 	cin >> t;
 	for(ll i=1;i<=t;i++)
 	{
 		ll n;
 		cin >> n;
 		if (countprimes[n] <= phi[n])
 			cout << phi[n] % MOD << "\n";
 		else
 		{
 			cout << binexp(phi[n], fact[countprimes[n] - phi[n]], MOD) << "\n";
 		}
 	}
 	return 0;
 } 