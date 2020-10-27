 
#include <bits/stdc++.h>

using namespace std;

#define sc(x) scanf("%d",&x)
#define INF (2e9)
#define F first
#define S second
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int N = 1e6 + 20;

int sz[N];
vi adj[N];
int col[N];
void pre(int u, int p) {
	sz[u] = 1;
	for (int v : adj[u])
		if (v != p) {
			pre(v, u);
			sz[u] += sz[v];
		}
}

bool big[N];
int cnt[N];
void add(int u, int p, int x) {

	cnt[col[u]] += x;
	for (int v : adj[u])
		if (v != p && !big[v])
			add(v, u, x);
}

void dfs(int u, int p, bool keep) {
	int mx = -1, bigChild = -1;
	for (int v : adj[u])
		if (v != p && sz[v] > mx)
			mx = sz[v], bigChild = v;

	for (int v : adj[u])
		if (v != p && v != bigChild)
			dfs(v, u, 0);
	if (bigChild != -1)
		dfs(bigChild, u, 1), big[bigChild] = 1;

	add(u, p, 1);
//cnt has answer now

	if (bigChild != -1)
		big[bigChild] = 0;

	if (!keep)
		add(u, p, -1);

}

int main() {

}
