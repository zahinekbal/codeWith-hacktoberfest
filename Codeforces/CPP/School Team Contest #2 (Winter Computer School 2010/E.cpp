// Tags: DP

#include <bits/stdc++.h>
#define ll long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
const int N = 205;
 
int k, a, b, dp[N][N];
string s;
 
int solve(int i, int l)
{
    if(i == s.size())
        return l == k;
 
    if(l == k)
        return 0;
 
    if(dp[i][l] != -1)
        return dp[i][l];
 
    dp[i][l] = 0;
 
    for(int j = a; j <= b; j++)
        if(i + j <= s.size())
            dp[i][l] |= solve(i + j, l + 1);
 
    return dp[i][l];
 
}
 
void build(int i, int l)
{
    if(i == s.size())
        return;
 
    if(l == k)
        return;
 
    for(int j = a; j <= b; j++)
    {
        if(i + j > s.size())
            break;
        if(!solve(i + j, l + 1))
            continue;
 
        cout << s.substr(i, j) << '\n';
        build(i + j, l + 1);
        return;
    }
}
 
int main()
{
    IO;
    memset(dp, -1, sizeof dp);
 
    cin >> k >> a >> b >> s;
 
    if(solve(0, 0))
        build(0, 0);
    else
        cout << "No solution";
 
}