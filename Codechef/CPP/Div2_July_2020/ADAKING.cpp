#include <bits/stdc++.h>
using namespace std;
#define fast_io        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int            long long
#define w(x)           while(x--)
#define t(x)           int x;cin >> x;while (x--)
#define rep(d,a,n)     for(auto d=a;d<=n;d++)
#define rep_(d,a,n)    for(auto d=a;d>=n;d--)
#define nl             "\n"
const int mod = 1e9 + 7;
const int inf = 1e18;

void fun() {
    int n;
    cin >> n;
    char arr[8][8];
    rep(i, 0, 7) {
        rep(j, 0, 7) {
            arr[i][j] = 'X';
        }
    }
    arr[0][0] = 'O';
    n--;
    rep(i, 0, 7) {
        rep(j, 0, 7) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (n == 0) {
                break;
            }
            else {
                arr[i][j] = '.';
                n--;
            }
        }
    }
    rep(i, 0, 7) {
        rep(j, 0, 7) {
            cout << arr[i][j];
        } cout << nl;
    } cout << nl;
}

int32_t main()
{
    fast_io;
    t(a) {
        fun();
    }
    return 0;
}