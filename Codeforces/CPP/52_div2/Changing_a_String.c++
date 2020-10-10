#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <queue>
#include <bitset>
#include <stack>
#include <unordered_map>
 
using namespace std;
 
#define all(v) (v).begin(),(v).end()
#define SRT(v) sort(all(v))
#define rall(v) (v).rbegin(),(v).rend()
#define rSRT(v) sort(rall(v))
#define sz(a) int((a).size())
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define PB push_back
#define mem(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define EPS 1e-9
#define Mod (ll)1000000007
#define oo (int)1<<30
#define OO (ll)1ll<<60
#define PI 3.141592653589793
#define F first
#define S second
#define pw(x) (x)*1LL*(x)
 
typedef stringstream ss;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii>vii;
typedef pair<int, ll> il;
typedef vector<vector<ii>> vvii;
typedef vector<vector<il>> vvil;
 
const int N = 1005;
 
string s, t; 
int dp[N][N];
 
int solve(int i, int j)
{
	if (i == sz(s) && j == sz(t)) return 0;
	if (i == sz(s)) return abs(sz(t) - j);
	if (j == sz(t)) return abs(sz(s) - i);
	if (~dp[i][j]) return dp[i][j];
	int ret = oo;
	if (s[i] == t[j]) ret = min(ret, solve(i + 1, j + 1));
	return dp[i][j] = min(ret, min(min(solve(i, j + 1) + 1, solve(i + 1, j) + 1), solve(i + 1, j + 1) + 1));
}
 
void build(int i, int j, int k = 1)
{
	if (i == sz(s) && j == sz(t)) return;
	if (i == sz(s)) {
		while (j < sz(t)) printf("INSERT %d %c\n", k++, t[j++]);
		return;
	}
	if (j == sz(t)) {
		while (i < sz(s)) printf("DELETE %d\n", k), i++;
		return;
	}
	if (s[i] == t[j]) {
		if (solve(i, j) == solve(i + 1, j + 1)) {
			build(i + 1, j + 1, k + 1);
			return;
		}
	}
	if (solve(i, j) == solve(i, j + 1) + 1) {
		printf("INSERT %d %c\n", j + 1, t[j]);
		build(i, j + 1, k + 1);
		return;
	}
	else if (solve(i, j) == solve(i + 1, j) + 1) {
		printf("DELETE %d\n", j + 1);
		build(i + 1, j, k);
		return;
	}
	else if (solve(i, j) == solve(i + 1, j + 1) + 1) {
		printf("REPLACE %d %c\n", j + 1, t[j]);
		build(i + 1, j + 1, k + 1);
		return;
	}
}
 
 
int main()
{
	cin >> s >> t; 
	mem(dp, -1);
	printf("%d\n", solve(0, 0));
	build(0, 0);
}
