// Tags: Implementation, Math

#include <bits/stdc++.h>
#define LL long long
using namespace std;
int aa[26][1000050], bb[26][1000050];
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    LL n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    LL g = __gcd(a.size(), b.size());
    LL l = a.size() * (b.size() / g), sz = a.size() * n, ans = 0;
    for (int i = 0; i < a.size(); i++)
        aa[a[i] - 'a'][i % g]++;
    for (int i = 0; i < b.size(); i++)
        bb[b[i] - 'a'][i % g]++;
    for (int i = 0; i < g; i++)
        for (int j = 0; j < 26; j++)
            ans += (LL)aa[j][i] * (LL)bb[j][i];
    ans *= (sz / l);
    cout << sz - ans;
    return 0;
}
