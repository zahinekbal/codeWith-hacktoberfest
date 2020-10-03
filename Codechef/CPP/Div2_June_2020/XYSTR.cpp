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
        string s1;
        cin>>s1;
        int len=s1.length();
        int i=0;int ans=0;
        while(i<=len-2){
            if(s1[i]=='x' && s1[i+1]=='y'){
                ans++;
                i+=2;
            }
            else if(s1[i]=='y' && s1[i+1]=='x'){
                ans++;
                i+=2;
            }
            else{
                i++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}