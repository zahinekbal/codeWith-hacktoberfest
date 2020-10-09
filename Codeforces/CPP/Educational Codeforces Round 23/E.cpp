// Tags: Bitmasks, Data Structures, Trees

#include<bits/stdc++.h>
#define ll long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
const int N = 2e5 + 50;
 
string cnv(int n)
{
	string ret;
	while(n)
		ret += (n % 2 + '0'), n /= 2;
	while(ret.size() < 30)
		ret += '0';
	reverse(ret.begin(), ret.end());
	return ret;
}
 
struct node
{
	node *ch[2];
	int c[2];
	node()
	{
		ch[0] = ch[1] = 0;
		c[0] = c[1] = 0;
	}
 
	void Go(string &n, int sgn, int i = 0)
	{
		if(i == 30)
			return;
		int x = n[i] - '0';
		if(!ch[x])
			ch[x] = new node();
		c[x] += sgn;
		ch[x]->Go(n, sgn, i + 1);
	}
}*root;
 
int Get(string &p, string &l)
{
	node *cur = root;
	int ans = 0;
	for(int i = 0; i < 30; i++)
	{
		int x = p[i] - '0';
		if(l[i] - '0')
		{
			ans += cur->c[x];
			if(cur->c[!x])
				cur = cur->ch[!x];
			else
				return ans;
		}
		else
		{
			if(cur->c[x])
				cur = cur->ch[x];
			else
				return ans;
		}
	}
	return ans;
}
 
int main()
{
	IO;
	root = new node();
	int q, t, p, l;
	cin >> q;
	while(q--)
	{
		cin >> t >> p;
		string pp = cnv(p);
		if(t == 1)
			root->Go(pp, 1);
		else if(t == 2)
			root->Go(pp, -1);
		else
		{
			cin >> l;
			string L = cnv(l);
			cout << Get(pp, L) << '\n';
		}
	}
}