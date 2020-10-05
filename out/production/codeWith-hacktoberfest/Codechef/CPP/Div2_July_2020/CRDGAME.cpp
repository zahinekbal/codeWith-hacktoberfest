#include <bits/stdc++.h>
using namespace std;
#define int       long long
#define w(x)      int x;cin >> x;while (x--)
#define rep(d,a,n)  for(int d=a;d<=n;d++)
#define rep_(d,a,n)  for(int d=a;d>=n;d--)
#define nl        "\n" 
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define oj  freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
const int inf=1e18;

void fun(){
    int n;
    cin>>n;
    int chefu=0,chomu=0;
    rep(i,0,n-1){
        int num1,num2,sume=0,sumi=0;cin>>num1>>num2;
        while(num1!=0){
            sume+=num1%10;
            num1/=10;
        }
        while(num2!=0){
            sumi+=num2%10;
            num2/=10;
        }
        if(sume>sumi){
            chefu++;
        }else if(sumi>sume){
            chomu++;
        }else{
            chomu++;
            chefu++;
        }
    }    
    if(chefu>chomu){
        cout<<0<<" "<<chefu<<nl;
    }else if(chefu<chomu){
        cout<<1<<" "<<chomu<<nl;
    }else{
        cout<<2<<" "<<chomu<<nl;
    }       
}
int32_t main()
{
    fast_io;
    w(t){
        fun();
    }
    
    return 0;
}
