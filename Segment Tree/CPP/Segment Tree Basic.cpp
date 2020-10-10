// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define IO                                                             \
    ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0), \
        cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }
double distance(double x1, double y1, double x2, double y2) {
    return hypot(fabs(x1 - x2), fabs(y1 - y2));
}
int comp_double(double a, double b) {
    if (fabs(a - b) <= EPS) return 0;  // equal
    return (a < b) ? -1 : 1;
}

struct segTree {
    ll size;
    vll tree;

    void init(ll n) {
        size = 1;
        while (size < n) size *= 2LL;
        tree.assign(size << 1, 0LL);
    }

    void build(vll& a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < a.sz) {
                tree[x] = a[lx];
            }
            return;
        }

        ll mid = lx + (rx - lx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);

        tree[x] = tree[x * 2 + 1] + tree[2 * x + 2];
    }

    void build(vll& a) { build(a, 0, 0, size); }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        // if we are in a leaf node
        if ((rx - lx) == 1) {
            tree[x] = v;
            return;
        }

        ll mid = lx + (rx - lx) / 2;

        // determine next step (left or right)
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        ll lft = 2 * x + 1;
        ll rgt = 2 * x + 2;
        tree[x] = tree[lft] + tree[rgt];
    }

    void set(ll i, ll v) { set(i, v, 0, 0, size); }

    ll get(ll l, ll r, ll x, ll lx, ll rx) {
        // outside
        if (lx >= r || l >= rx) {
            return 0;
        }

        // inside
        if (lx >= l && rx <= r) {
            return tree[x];
        }

        // partial
        ll mid = lx + (rx - lx) / 2;

        ll sm_1 = get(l, r, 2 * x + 1, lx, mid);
        ll sm_2 = get(l, r, 2 * x + 2, mid, rx);

        return sm_1 + sm_2;
    };

    ll get(ll l, ll r) { return get(l, r, 0, 0, size); }
};

int main() {
    IO;
#ifndef ONLINE_JUDGE
    freopen("In.txt", "r", stdin);
#else
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
#endif
    ll n, m;
    cin >> n >> m;

    segTree st;
    st.init(n);

    // !note
    // here we use the set function (which works in log) to set the initial
    // value of the array
    // for (int i = 0; i < n; i++) {
    //     ll x;
    //     cin >> x;
    //     st.set(i, x);
    // }

    // *note
    // its better to use build function to set all the values of the array and
    // build the tree in linear time
    vll a(n);
    for (ll& i : a) cin >> i;

    st.build(a);

    while (m--) {
        ll op;
        cin >> op;
        if (op == 1) {  // update
            ll i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {  // get sum
            ll l, r;
            cin >> l >> r;
            ll ret = st.get(l, r);
            cout << ret << endl;
        }
    }
}

// notes:
// 1. check base conditions return values
// 2. check initialization values
