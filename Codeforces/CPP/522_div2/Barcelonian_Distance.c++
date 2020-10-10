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
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define PB push_back
#define trav(c,i) for(typeof((c).begin()i=(c).begin();i!=(c).end();i++)
#define mem(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define EPS 1e-9
#define Mod (ll)1000000007
#define oo (int)1<<30
#define OO (ll)1<<60
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
typedef vector<vector<ii> > vvii;
typedef vector<vector<il> > vvil;

long double a, b, c; pair<long double, long double>A[2], B[2];
 
long double intersectH(int y)
{
	long double ret = (long double)(b * 1ll * y + c) / (long double)a;
	if (ret) ret *= -1;
	return ret;
}
 
long double intersectV(int x)
{
	long double ret = (long double)(a * 1ll * x + c) / (long double)b;
	if (ret) ret *= -1;
	return ret;
}
 
long double getDist(long double x1, long double y1, long double x2, long double y2)
{
	long double dist =  (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return sqrt(dist);
}
 
int main()
{
	//freopen("intput.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	long double x1, y1, x2, y2; 
	cin>>a>>b>>c>>x1>>y1>>x2>>y2;
	long double ans = abs(x1 - x2) + abs(y1 - y2);
	if (a == 0 || b == 0) {
		printf("%.10Lf", ans);
		return 0;
	}
	A[0] = MP(x1, intersectV(x1));
	A[1] = MP(intersectH(y1), y1);
	B[0] = MP(x2, intersectV(x2));
	B[1] = MP(intersectH(y2), y2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ans = min(ans, getDist(x1, y1, A[i].F, A[i].S) + getDist(A[i].F, A[i].S, B[j].F, B[j].S) + getDist(B[j].F, B[j].S, x2, y2));
		}
	}
	printf("%.10Lf", ans);
}
