#include <bits/stdc++.h>

using namespace std;

void fileioe()
{
    freopen("input.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    freopen("error.txt","w",stderr);
}
#ifndef ONLINE_JUDGE
#define fioe() fileioe()
#else
#define fioe() 1
#endif

#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define endl "\n"
#define pi 3.1415926535897932384626433832795
#define mod 1000000007
#define ff first
#define ss second 
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define all(a) (a).begin(),(a).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define w(n) while(n--)

typedef long long int ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vl;
typedef vector<ll> v;
typedef set<ll> st;
#define PI 3.14159265
typedef pair<ll,ll> pll;
ll bin(	ll a,ll b,bitset<64>w,bitset<64>r,int p);
vl ar[200001];
ll visited[200001];
ll cc;
ll mx=0;
ll ans=-1;
int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll n=s.length();
//		cout<<n<<endl;
		stack<pair<char, int> > st;
		vector<ll>v;
		int p=-1;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]==')')
			{
				st.push({s[i],i});
				v.push_back(p);
			}
				
			else
			{
				if(st.empty())
				{
					p=-1;
					v.push_back(-1);
					continue;
				}
				if(!st.empty() && st.top().first==')')
				{
					p=st.top().second;
					v.push_back(st.top().second);
					st.pop();
				}
			}
		}
		
		reverse(v.begin(),v.end());
//		for(int i=0;i<v.size();i++)
//			cout<<v[i]<<" ";
		int q;
		cin>>q;
		ll a[q];
		while(q--)
		{
			ll x;
			cin>>x;
			x--;
			if(v[x]==-1)
			cout<<v[x]<<endl;
			else
			cout<<v[x]+1<<endl;
			
		}
	}
}
