#include <bits/stdc++.h>
using namespace std;
#define int       long long
#define w(x)      int x;cin >> x;while (x--)
#define rep(d,a,n)  for(int d=a;d<=n;d++) 
const int inf=1e18;
void oj()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return;
}

int32_t main()
{
    //oj();
    w(t){
        int n,k;
        cin>>n>>k;
        int arr[n];int ans=0;
        rep(i,0,n-1){
            cin>>arr[i];
            if(arr[i]>k){
                ans+=(arr[i]-k);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}