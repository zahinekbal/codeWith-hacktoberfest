#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 70
int a[N][N],n;
int getid(int x,int y){return (x-1)*n+y;}
void flip(int l)
{
	for(int i=1;i<=l;i++)
	{
		for(int j=1;j<i;j++) swap(a[i][j],a[j][i]);
	}
}
void work()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=read();
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		bool ok=1;
		for(int j=1;j<=i;j++) if(a[i][j]!=getid(i,j)) ok=0;
		for(int j=1;j<=i;j++) if(a[j][i]!=getid(j,i)) ok=0;
		if(!ok) ans++,flip(i);
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}
