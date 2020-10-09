// Tags: Combinatorics, Implementation, Math, Sortings

#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    map<int,int>m;
    int n; cin>>n;
    LL ans=0,x;
    vector<int>a(n),b;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    for(auto i:a)if(i==a[0]||i==a[1]||i==a[2])b.push_back(i),m[i]++;
    if(a[0]==a[1]&&a[0]==a[2])
    {
        for(int i=0;i<b.size()-1;i++)
        {
            x=b.size()-i-2;
            ans+=(x*(x+1))/2;
        }
        cout<<ans;
    }
    else if(a[1]==a[2])
    {
        x=m[a[1]]-1;
        cout<<(x*(x+1))/2;
    }
    else
    {
        cout<<m[a[2]];
    }
    return 0;
}
