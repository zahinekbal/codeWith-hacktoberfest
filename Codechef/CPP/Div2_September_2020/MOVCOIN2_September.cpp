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
#define mod 1000000007
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 300005
struct Trie
{
	int ch[N*20][2],siz[N*20],cnt,sum; 
	void init()
	{
		for(int i=0;i<=cnt;i++) ch[i][0]=ch[i][1]=0;
		for(int i=0;i<=cnt;i++) siz[i]=0;
		cnt=1; sum=0;
	}
	void insert(int v)
	{
		int u=1;
		for(int i=0;i<=18;i++)
		{
			int c=v>>i&1;
			if(!ch[u][c]) ch[u][c]=++cnt;
			u=ch[u][c];
			siz[u]++;
		}
		sum^=v;
	}
	void plus1()
	{
		int u=1;
		for(int i=0;i<=18;i++)
		{
			if(!u) return ;
			if((siz[ch[u][0]]-siz[ch[u][1]])&1) sum^=(1<<i);
			swap(ch[u][0],ch[u][1]);
			u=ch[u][0];
		}
	}
	void minus1()
	{
		int u=1;
		for(int i=0;i<=18;i++)
		{
			if(!u) return ;
			if((siz[ch[u][0]]-siz[ch[u][1]])&1) sum^=(1<<i);
			swap(ch[u][0],ch[u][1]);
			u=ch[u][1];
		}
	}
}tr;
vector<int> G[N];
int n,rest,rt,maxp[N],vis[N],val[N],ans[N],siz[N],a[N];
void getrt(int u,int f)
{
	siz[u]=1; int maxn=0;
	for(int v:G[u])
	{
		if(v==f||vis[v]) continue;
		getrt(v,u);
		siz[u]+=siz[v];
		maxn=max(maxn,siz[v]);
	}
	maxn=max(maxn,rest-siz[u]);
	maxp[u]=maxn;
	if(maxp[u]<maxp[rt]) rt=u;
}
int dep[N],maxd=0;
void dfs1(int u,int f)
{
	dep[u]=dep[f]+1; maxd=max(maxd,dep[u]);
	if(a[u]) tr.insert(dep[u]);
	for(int v:G[u])
	{
		if(v!=f&&!vis[v]) dfs1(v,u);
	}
}
int Res[N],RES[N];
void dfs2(int u,int f)
{
	dep[u]=dep[f]+1; maxd=max(maxd,dep[u]);
	if(a[u])
	{
		tr.insert(dep[u]);
		// cout<<u<<" "<<dep[u]<<endl;
	}
	for(int v:G[u])
	{
		if(v!=f&&!vis[v]) dfs2(v,u);
	}
}
void dfs3(int u,int f)
{
	dep[u]=dep[f]+1;
	// printf("%d %d\n",u,Res[dep[u]]^RES[dep[u]]);
	ans[u]^=Res[dep[u]]^RES[dep[u]];
	for(int v:G[u])
	{
		if(v!=f&&!vis[v]) dfs3(v,u);
	}
}
void solve(int u)
{
	tr.init();
	vis[u]=1; maxd=0; dep[0]=-1; dfs1(u,0);
	Res[0]=tr.sum; ans[u]^=Res[0];
	// printf("%d\n",u);
	for(int i=1;i<=maxd;i++)
	{
		tr.plus1();
		Res[i]=tr.sum;
	}
	// for(int i=0;i<=maxd;i++) printf("%d%c",Res[i]," \n"[i==maxd]);
	for(int v:G[u])
	{
		if(vis[v]) continue;
		tr.init(); maxd=0;
		dep[u]=0; dfs2(v,u);
		RES[0]=tr.sum;
		for(int i=1;i<=maxd;i++)
		{
			tr.plus1();
			RES[i]=tr.sum;
		}
		dep[u]=0; dfs3(v,u);
	}
	int nowsiz=rest;
	for(int v:G[u])
	{
		if(vis[v]) continue;
		maxp[rt=0]=inf;
		if(siz[v]<siz[u]) rest=siz[v];
		else rest=nowsiz-siz[u];
		getrt(v,u);
		solve(rt);
	}
}
void work()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++) a[i]=read()&1;
	maxp[rt=0]=inf; rest=n;
	getrt(1,0);
	solve(rt);
	int Ans=0,pw=1;
	for(int i=1;i<=n;i++)
	{
		pw=add(pw,pw);
		if(!ans[i]) Ans=add(Ans,pw);
	}
	cout<<Ans<<endl;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) ans[i]=vis[i]=0;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}