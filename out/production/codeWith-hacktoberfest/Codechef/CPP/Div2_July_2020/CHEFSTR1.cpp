#include <bits/stdc++.h>
using namespace std;
#define int       long long
#define w(x)      int x;cin >> x;while (x--)
#define rep(d,a,n)  for(int d=a;d<=n;d++)
#define rep_(d,a,n)  for(int d=a;d>=n;d--)
#define nl        "\n" 
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define oj  freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
const int inf=1e18;

void fun(){
    int n;
    cin>>n;
    int *arr=new int[n];
    int ans=0;
    rep(i,0,n-1){
        cin>>arr[i];
        if(i){
            ans+=(abs(arr[i]-arr[i-1])-1);
        }
    } 
    cout<<ans<<nl;       
}
int32_t main()
{

    fast_io;
    w(t){
        fun();
    }
    
    return 0;
}
