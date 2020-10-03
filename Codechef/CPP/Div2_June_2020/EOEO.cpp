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
int ans(int tom){
    int vss=tom;
    if(tom%2!=0){
        return (tom-1)/2;
    }else{
        int step=1;
        while(tom%2==0){
            tom/=2;
            step++;
        }
        if(tom==1){
            return 0;
        }else{
            return vss/((int)pow(2,step));
        }
    }
}
int32_t main()
{
    //oj();
    w(t){
        int n;
        cin>>n;
        int answer=ans(n);
        cout<<answer<<"\n";
    }
    return 0;
}