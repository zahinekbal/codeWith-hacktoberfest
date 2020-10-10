#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, l, r, m;
    cin >> n;
    vector<int> a(n, 0);
    for (l = 0; l < n; l++)
        cin >> a[l];
    l = 0, r = n - 1, m = 0;

    while (m <= r)
    {
        if (a[m] == 0)
            swap(a[l++], a[m++]);
        else if (a[m] == 1)
            m++;
        else
            swap(a[m], a[r--]);
    }
    for (l = 0; l < n; l++)
        cout << a[l] << " ";
    return 0;
}
