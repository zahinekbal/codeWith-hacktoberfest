#include <bits/stdc++.h>
using namespace std;
#define ll          long long int
void fun(){
    ll n;
    cin>>n;
    unordered_set<ll>x;
    unordered_set<ll>y;
    ll ni=4*n-1;
    while(ni--){
        ll x1,y1;
        cin>>x1>>y1;
        if(x.count(x1)){
            x.erase(x1);
        }else{
            x.insert(x1);
        }
        if(y.count(y1)){
            y.erase(y1);
        }else{
            y.insert(y1);
        }
        }
        auto itr=x.begin();
        auto itr2=y.begin();
        cout<<(*itr)<<" "<<(*itr2)<<endl;

}
int main()
{
    ll t;
    cin>>t;
    while(t--){
        fun();
    }
    return 0;
}
