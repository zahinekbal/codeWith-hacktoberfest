#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[4],c=0;
		for(int i=0;i<n;i++){
			cin>>a[0]>>a[1]>>a[2]>>a[3];
			if(a[1]==a[2])
				c=1;
		}
		if(m%2)
			cout<<"NO"<<endl;
		else{
			if(c==1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}