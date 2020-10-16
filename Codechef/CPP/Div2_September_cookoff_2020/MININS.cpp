#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
    while(t--){
        int n,k=0,ch_size=1,s=0;
        cin>>n;
        int a[n];
        vector<int> temp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i==0||__gcd(a[i],a[i-1])==1)
            {
                temp.push_back(1);
                k++;
            }
            else
            temp[k-1]++;
        }
        int fl=0;
        if(k>1&&__gcd(a[0],a[n-1])>1)
        {
            temp[0]+=temp.back();
            temp.pop_back();
        }
        if(k==1&&__gcd(a[0],a[n-1])>1)
        fl=1;
  
        vector<int> ans(n+1,0);
        for(auto var:temp){
            for(float i=2;i<=var;i++){
                if(fl)
                ans[i]+=ceil(var/(i-1));
                else
                ans[i]+=ceil(var/(i-1))-1;
            }
        }
        for(int i=2;i<=n;i++)
        cout<<ans[i]<<" ";
    
        cout<<"\n";
        
    }
	return 0;
}

