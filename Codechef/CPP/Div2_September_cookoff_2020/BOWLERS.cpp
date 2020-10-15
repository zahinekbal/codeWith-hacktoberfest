#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
    while(t--){
        int n,k,l,c=0,c1=0;
       cin>>n>>k>>l;
       if(n==1)
       cout<<"1\n";
       else if(k==1||k*l<n)
       cout<<"-1\n";
       else{
           for(int i=1;i<=l;i++){
               for(int j=1;j<=k;j++){
                    cout<<j<<" ";
                   c1++;
                    if(c1==n){
                  c=1;
                   break;
                   }
                  
                  
               }
               if(c==1)
               break;
           }
           cout<<"\n";
       }
        
    }
	return 0;
}

