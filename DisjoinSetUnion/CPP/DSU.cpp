#include <bits/stdc++.h>
using namespace std;

#define rank rnk
const int N = 1e5 + 5;
int rank[N], p[N];

void init() {
	for (int i = 0; i < N; i++)
		rank[i] = 0, p[i] = i;
}

int findp(int n) {
	return n == p[n] ? n : p[n] = findp(p[n]);
}

bool merge(int u, int v) {
	u = findp(u);
	v = findp(v);
	if (u == v)
		return false;
	if (rank[u] < rank[v])
		swap(u, v);

	if (rank[u] == rank[v])
		rank[u]++;

	p[v]=u;
	return true;
}

bool isSameSet(int u,int v){
	return findp(u)==findp(v);
}


