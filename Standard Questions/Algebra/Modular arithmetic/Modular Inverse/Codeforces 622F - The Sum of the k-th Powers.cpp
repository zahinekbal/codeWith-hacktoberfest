/*
 * File: Codeforces 622F - The Sum of the k-th Powers
 * Algorithm: Modular Inverse
 * Created Date: Tuesday August 4th 2020
 * Author: preetam rane
 */

#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 60,mod = 1e9 + 7;
int n,k;
int a[N];

inline int ksm(int x,int y)
{
	int ans = 1;
	while(y)
	{
		if(y&1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}
	return ans;
}

int s1[N],s2[N],inv[N];
inline int lagrange(int*a,int n,int pos)
{
	if(pos <= n) return a[pos];
	s1[0] = s2[n + 1] = 1;
	for(register int i = 1;i <= n; ++ i) 
        s1[i] = 1ll * ((pos - i) % mod + mod) % mod * s1[i-1] % mod;

	for(register int i = n;i >= 1; -- i) 
        s2[i] = 1ll * ((pos - i) % mod + mod) % mod * s2[i+1] % mod;

	int ans = 0;
	for(register int i = 1;i <= n; ++ i)
		ans = (ans + 1ll * a[i] * s1[i-1] % mod *s2[i+1] % mod
			* inv[i-1] % mod * inv[n-i] % mod * ((n-i)&1?mod-1:1))%mod;
	ans = (ans % mod + mod) % mod;
	return ans;
}

int main()
{
	cin >> n >> k;
	for(register int i = 1;i <= k+2; ++ i) 
        a[i] = ksm(i,k);

	for(register int i = 1;i <= k+2; ++ i) 
        a[i] = (a[i-1] + a[i]) % mod;

	inv[0] = 1; inv[1] = 1;
	for(register int i = 2;i <= k+2; ++ i) 
        inv[i] = 1ll * (mod - mod/i) * inv[mod%i] % mod;

	for(register int i = 2;i <= k+2; ++ i) 
        inv[i] = 1ll * inv[i] * inv[i-1] % mod;

	cout << lagrange(a,k+2,n) << endl;

	return 0;
}