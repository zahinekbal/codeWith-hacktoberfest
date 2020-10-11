// Tags: DP, Math

#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define f first
#define s second
using namespace std;
 
const int N = 105, M = 2505, mod = 1e9 + 7;
 
int t, n, m, dp[N][M];
string s;
 
int sum()
{
    int ret = 0;
    for(auto i : s)
        ret += i - 'a' + 1;
    return ret;
}
 
int solve(int i, int sm)
{
    if(i == 0)
        return (sm == 0);
    int &x = dp[i][sm];
    if(x != -1)
        return x;
    x = 0;
    for(int j = 1; j <= min(sm, 26); j++)
        x = (x + solve(i - 1, sm - j)) % mod;
    return x;
}
 
int main()
{
    IO;
    memset(dp, -1, sizeof dp);
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.size();
        m = sum();
        cout << (solve(n, m) - 1 + mod) % mod << '\n';
    }
}
