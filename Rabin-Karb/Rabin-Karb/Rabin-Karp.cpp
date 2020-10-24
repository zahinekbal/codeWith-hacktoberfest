#include <bits/stdc++.h>
using namespace std;

const int dx[] = { 0, 0, -1, 1, 1, -1, -1, 1 };
const int dy[] = { -1, 1, 0, 0, -1, 1, -1, 1 };

const int mod = 1e9 + 7;
int base = 128;
ll inverse;
ll pw(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b % 2)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret % mod;
}
int main() {
	int k;
	string str;

	cin >> k >> str;
	inverse = pw(base, mod - 2);

	ll h1 = 0, h2 = 0, p = 1;
	ll ans = 0;
	for (int i = 0, j = k - 1; i < k; ++i, --j) {
		if (i)
			p = p * base % mod;
		h1 = (h1 + str[j] * p) % mod;
		h2 = (h2 + str[i] * p) % mod;
	}

	ans += h1 == h2;
	for (int i = 0; i < sz(str) - k; i++) {
		h1 = (h1 - p * str[i] % mod + mod) % mod;
		h1 = h1 * base % mod;
		h1 = (h1 + str[i + k]) % mod;

		h2 = (h2 - str[i] + mod) % mod;
		h2 = h2 * inverse % mod;
		h2 = (h2 + str[i + k] * p % mod) % mod;

		ans += h1 == h2;
	}

	cout << ans << endl;
	return 0;
}
