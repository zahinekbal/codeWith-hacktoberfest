#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main() {
	int t;
	cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],sum=0,l=0,r=n-1,cnt=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>=0)
            sum=sum+a[i];
            else
            cnt++;
        }
        cout<<sum<<endl;
        if(cnt==0||cnt==n){
            cout<<"0";
        }
        else{
            vector<int> v1,v2;
 
        while(l < r) {
			while(l < n && a[l] < 0)
				l++;
 
			while(r >= 0 && a[r] > 0)
				r--;
 
			if(l < r) {
				v1.push_back(l);
				v2.push_back(r);
				l++;
				r--;
			}
		}
        int k=v1.size()+v2.size();
        reverse(v2.begin(), v2.end());
        cout<<k;
        for(int i=0;i<v1.size();i++){
            cout<<" "<<v1[i]+1;
        }
        for(int i=0;i<v2.size();i++){
            cout<<" "<<v2[i]+1;
        }}
        cout<<endl;
        
        
    }
	return 0;
}

