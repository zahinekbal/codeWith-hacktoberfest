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

void ans(int n){
    int arr[n][n]={};
    int num=1;
    for(int i=0;i<n;i++){
        if(i%2==0){
        for(int j=0;j<n;j++){
            arr[i][j]=num;
            num++;
        }
        }
        else{
            for(int k=n-1;k>=0;k--){
                arr[i][k]=num;
                num++;
            }
        }
    }
    rep(i,0,n-1){
        rep(j,0,n-1){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}
int32_t main()
{
    //oj();
    w(t){
        int n;
        cin>>n;
        ans(n);
    }
    return 0;
}