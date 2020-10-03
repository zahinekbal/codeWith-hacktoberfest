#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007LL
#define For(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define int long long
#define ld long double
#define endl "\n"
int power_mod(int num,int g)
{
    if(g==0)return 1;
    if(g%2==1)return (num*power_mod((num*num)%mod,g/2))%mod;
    return power_mod((num*num)%mod,g/2);
}
int power(int num,int g)
{
    if(g==0)return 1;
    if(g%2==1)return (num*power((num*num),g/2));
    return power((num*num),g/2);
}
#define N 10001
int n,m,k;
vector<pair<int,int> > vec[N];
pair<int,int> a[N];
bool visit[N];
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n>>m>>k;
    For(i,n)cin>>a[i].ff;
    For(i,n)a[i].ss=i+1;
    sort(a,a+n);
    vector<int> vec1;
    For(i,m){
        int u,v,s;
        cin>>u>>v>>s;
        vec[u].pb(mp(s,v));
        vec[v].pb(mp(s,u));
    }
    set<pair<int,int> > st;
    for(int i=1;i<=n;i++)
        sort(vec[i].begin(), vec[i].end());
    for(int po=0;po<n;po++){
        int i=a[po].ss;
        if(vec[i].size()<=k-1)continue;
        bool is=false;
        mem(visit,false);
        visit[i]=true;
        int x=i,y=-1;
        int u=1;
        while(u<256){
            u++;
            int l=vec[x].size();
            y=-1;
            int z=INT_MAX;
            int o=0;
            For(j,l) {
                if(st.find(mp(x,vec[x][j].ss))!=st.end()){
                    continue;
                }
                vec[x][o]=vec[x][j];
                o++;
            }
            while(l>o){
                l--;
                vec[x].pop_back();
            }
            For(j,l) {
                if(z>vec[x][j].ff){
                    z=vec[x][j].ff;
                    y=vec[x][j].ss;
                }
            }
            
            if(y==-1)break;
            if(visit[y])break;
            For(j,l)visit[vec[x][j].ss]=true;
            st.insert(mp(x,y));
            st.insert(mp(y,x));
            x=y;
            is=true;
        }
        // cout<<endl;
        if(is){
            // cout<<i<<endl;
            vec1.pb(i);
            po--;
        }

    }
    cout<<vec1.size()<<endl;
    For(i,vec1.size())cout<<vec1[i]<<" ";
    cout<<endl;
    int c[n+1];
    for(int i=1;i<=n;i++)c[i]=-1;
    for(int i=1;i<=n;i++){
        set<int> st1;
        For(j,vec[i].size()) {
            st1.insert(c[vec[i][j].ss]);
        }
        int x=1;
        for(auto it:st1){
            if(it==x)x++;
        }
        c[i]=x;
    }
    for(int i=1;i<=n;i++)cout<<c[i]<<" ";cout<<endl;

    return 0;
}