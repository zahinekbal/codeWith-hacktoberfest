#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,j,k;
    vector<int> v;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            int vis[n] = {0};
            vis[i]=true;
            if(i==0)
            {
                for(j=i+1;j<n;j++)
                    if(a[j]<a[i])
                        vis[j]=true;
            }
            else
            {
                for(j=i+1;j<n;j++)
                    if(a[j]<a[i])
                        vis[j]=true;
                int m=*max_element(a,a+i);
                if(m>a[i])
                {
                    for(j=i+1;j<n;j++)
                        if(a[j]<m)
                            vis[j]=true;
                    for(j=0;j<i;j++)
                        for(k=i;k<n;k++)
                            if(a[k]<a[j])
                            {
                                vis[j]=true;
                                break;
                            }
                }
                else
                {
                    for(j=0;j<i;j++)
                        for(k=i;k<n;k++)
                            if(a[k]<a[j])
                            {
                                vis[j]=true;
                                break;
                            }
                }
            }
            v.push_back(count(vis,vis + n,1));
        }
        cout<<(*min_element(v.begin(), v.end()))<<" "<<(*max_element(v.begin(), v.end()))<<"\n";
        v.clear();
    }
}