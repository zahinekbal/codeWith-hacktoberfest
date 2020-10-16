#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n==0)
        cout<<"0\n";
        else{
        string s;
        cin>>s;
        vector<int> m1,m2;
        int count=0,c=0,l=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
            {   count++;
                if(i==0)
                c=1;
                l++;
                if(i==n-1)
                m1.push_back(l);
            }
            else
            {
                if(c==1&&l>0)
                m1.push_back(l);
                else if(l>0)
                m2.push_back(l);
                l=0;
                c=0;
            }
            
        }
        if(count==n){
            cout<<"0\n";
        }
        else{
               sort(m1.begin(),m1.end());
          sort(m2.begin(),m2.end());
            
            int gcuts=0,cnt=0;
            if(k%2!=0){
                k--;
                if(m1.size()>0){
                    gcuts+=m1[m1.size()-1];
                    cnt++;
                }
            }
            int i=0;
            for(i=m2.size()-1;i>=0;i--){
                if(k>2){
                    gcuts+=m2[i];
                    k=k-2;
                }
                else
                break;
            }
            
            if(k>=2){
                int s2=0;
                    for(int j=m1.size()-1-cnt;j>=0;j--){
                        s2=s2+m1[j];
                    }
                if(i>=0){
                    
                    gcuts+=max(s2,m2[i]);
                }
                else{
                    gcuts+=s2;
                }
            }
            cout<<count-gcuts<<"\n";
        
        }
        }
        
    }
	return 0;
}

