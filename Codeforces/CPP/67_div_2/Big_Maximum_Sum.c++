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

const int N = 250005;
 
struct node { ll best, suml, sumr, tot; };
 
node seg[4 * N]; vvi adj; int arr[N], n, m;
ll sl[60], sr[60], sb[60], st[60];
 
ll getBest(int idx)
{
	ll sum = 0, ans = -OO;
	for (ll x : adj[idx]) {
		ans = max(ans, x);
		sum += x;
		if (sum < 0) sum = 0;
		else ans = max(ans, sum);
	}
	return ans;
}
 
ll getLeft(int idx)
{
	ll sum = 0, ans = -OO;
	for (int i = 0; i < sz(adj[idx]); i++) {
		sum += adj[idx][i];
		ans = max(ans, sum);
	}
	return ans;
}
 
ll getRight(int idx)
{
	ll sum = 0, ans = -OO;
	for (int i = sz(adj[idx]) - 1; i >= 0; i--) {
		sum += adj[idx][i];
		ans = max(ans, sum);
	}
	return ans;
}
 
ll getTot(int idx)
{
	ll sum = 0;
	for (ll x : adj[idx]) sum += x;
	return sum;
}
 
void getSums()
{
	for (int i = 1; i <= n; i++) {
		sb[i] = getBest(i);
		sl[i] = getLeft(i);
		sr[i] = getRight(i);
		st[i] = getTot(i);
	}
}
 
void build(int id = 1, int l = 0, int r = m)
{
	if (r - l < 2) {
		seg[id] = { sb[arr[l]], sl[arr[l]], sr[arr[l]], st[arr[l]] };
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	seg[id].tot = seg[2 * id].tot + seg[2 * id + 1].tot;
	seg[id].suml = max(seg[2 * id].suml, seg[2 * id].tot + seg[2 * id + 1].suml);
	seg[id].sumr = max(seg[2 * id + 1].sumr, seg[2 * id + 1].tot + seg[2 * id].sumr);
	seg[id].best = max(max(seg[2 * id].best, seg[2 * id + 1].best), seg[2 * id].sumr + seg[2 * id + 1].suml);
}
 
int main()
{
	sc(n); sc(m); adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int len; sc(len); adj[i].resize(len);
		for (int j = 0; j < len; j++) sc(adj[i][j]);
	}
	for (int i = 0; i < m; i++) sc(arr[i]);
	getSums(); build();
	printf("%lld", seg[1].best);
}
