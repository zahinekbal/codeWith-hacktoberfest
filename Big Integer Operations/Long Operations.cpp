// #Long Multiply
string longMult(string s1, string s2) {
	int n1 = s1.sz, n2 = s2.sz;
	if (n1 == 0 || n2 == 0) return "0";
	vi res(n1 + n2, 0);
	int i_n1 = 0, i_n2 = 0;
	for (int i = n1 - 1; i >= 0; i--) {
		int crr = 0, n1 = s1[i] - '0';
		i_n2 = 0;
		for (int j = n2 - 1; j >= 0; j--) {
			int n2 = s2[j] - '0';
			int sumi = n1 * n2 + res[i_n1 + i_n2] + crr;
			crr = sumi / 10;
			res[i_n1 + i_n2] = sumi % 10;
			i_n2++;
		}
		if (crr > 0) res[i_n1 + i_n2] += crr;
		i_n1++;
	}
	int i = res.sz - 1;
	while (i >= 0 && res[i] == 0) i--;
	if (i == -1) return "0";
	string s = "";
	while (i >= 0) s += to_string(res[i--]);
	return s;
}


// #Long Sum
string longSum(string s1, string s2) {
	if (s1.sz > s2.sz) swap(s1, s2);
	string str = "";
	int n1 = s1.sz, n2 = s2.sz;
	reverse(all(s1));
	reverse(all(s2));
	int crr = 0;
	for(int i = 0; i < n1; i++){
		int sumi = ((s1[i] - '0') + (s2[i] - '0') + crr);
		str.push_back(sumi % 10 + '0');
		crr = sumi / 10;
	}
	for(int i = n1 ; i < n2 ; i++){
		int sumi = ((s2[i] - '0') + crr);
		str.push_back(sumi % 10 + '0');
		crr = sumi / 10;
	}
	if (crr) str.push_back(crr + '0');
	reverse(all(str));
	return str;
}


// # Long Division
string longDivision(string n, ll div) {
	string ans;
	ll idx = 0;
	ll tmp = n[idx] - '0';
	while (tmp < div) tmp = tmp * 10 + (n[++idx] - '0');
	while (n.sz > idx) {
		ans += (tmp / div) + '0';
		tmp = (tmp % div) * 10 + n[++idx] - '0';
	}
	if (!ans.sz) return "0";
	return ans;
}
