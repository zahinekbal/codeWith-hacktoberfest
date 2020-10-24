#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
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

int f[100500];
int n;
char str[100500];
void buildF() {
	int j = 0;
	for (int i = 1; i < n; i++) {
		if (str[i] == str[j])
			f[i] = ++j;
		else {
			while (j && str[j] != str[i])
				j = f[j - 1];

			if (str[i] == str[j])
				f[i] = ++j;
			else
				f[i] = 0;
		}
	}

}
int main() {
	scanf("%s",str);
	n=strlen(str);
	buildF();
	
	
	return 0;
}

