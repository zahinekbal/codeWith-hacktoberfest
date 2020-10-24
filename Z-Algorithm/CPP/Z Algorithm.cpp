#include <bits/stdc++.h>
using namespace std;


int z[100500];
string str;

void fillZ() {
	int n = sz(str);
	int l, r;
	l = r = 0;
	for (int i = 1; i < n; i++) {
		if (i > r) {
			l = r = i;
			while (r < n && str[r] == str[r - l])
				r++;
			r--;
			z[i] = r - l + 1;
		} else {
			int k = i - l;
			if (z[k] < r - i + 1)
				z[i] = z[k];
			else {
				while (r < n && str[r] == str[r - l])
					r++;
				r--;
				z[i] = r - l + 1;
			}
		}
	}
}
int main() {
	string state, patt;
	cin >> state >> patt;
	str = patt + "%" + state;
	fillZ();
	for (int i = 0; i < sz(str); i++)
		if (z[i] == sz(patt))
			cout << i - sz(patt) - 1 << endl;


	return 0;
}

