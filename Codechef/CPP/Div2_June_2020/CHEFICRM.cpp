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
bool ans(int n,int arr[]){
    vector<int>rs_5;
    vector<int>rs_10;
    vector<int>rs_15;
    rep(i,0,n-1){
        if(arr[i]==5){
            rs_5.push_back(5);
        }if(arr[i]==10){
            if(rs_5.size()==0){
                return false;
            }else{
                rs_5.pop_back();
                rs_10.push_back(10);
            }
        }if(arr[i]==15){
            if(rs_10.size()!=0){
                rs_10.pop_back();
                rs_15.push_back(15);
            }else if(rs_5.size()>=2){
                rs_5.pop_back();
                rs_5.pop_back();
                rs_15.push_back(15);
            }else{
                return false;
            }
        }
    }
    return true;
}
int32_t main()
{
    //oj();
    w(t){
        int n;
        cin>>n;
        int arr[n];
        rep(i,0,n-1){
            cin>>arr[i];
        }
        if(ans(n,arr)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}