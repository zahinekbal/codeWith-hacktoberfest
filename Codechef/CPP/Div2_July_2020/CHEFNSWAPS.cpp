#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define nl "\n"
void print(vector<int>arr){for(auto i:arr){cout<<i<<" ";}cout<<nl;}

void fun()
{
    int n;
    cin >> n;
    int *x=new int[n];
    int *y=new int[n];
    int minu_a,minu_b;
    for(int i=0;i<n;i++){
        cin>>x[i];
        if(i==0){
            minu_a=x[0];
        }else{
            minu_a=min(minu_a,x[i]);
        }
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
        if(i==0){
            minu_b=y[0];
        }else{
            minu_b=min(minu_b,y[i]);
        }
    }
    sort(x,x+n);
    sort(y,y+n);
    vector<int>te(n);
    vector<int>tr(n);
    auto a_b=set_difference(x,x+n,y,y+n,tr.begin());
    auto b_a=set_difference(y,y+n,x,x+n,te.begin());
    delete x,y;
    int len1=0;int len2=0;
    vector<int>a;
    vector<int>b;
    for(auto itr=tr.begin();itr<a_b;itr++,itr++){
//        cout<<*itr<<nl;
        if((*itr)==(*(itr+1))){
            b.push_back(*itr);
            len1++;
        }else{
            cout<<-1<<nl;
            return;
        }
    }
    for(auto itr=te.begin();itr<b_a;itr++,itr++){
//        cout<<*itr<<nl;
        if((*itr)==(*(itr+1))){
            a.push_back(*itr);
            len2++;
        }else{
            cout<<-1<<nl;
            return;
        }
    }
//    print(a);print(b);
    int total=0;
    if(len1!=len2){cout<<-1<<nl;return;}
    for(int i=0,j=b.size()-1;i<a.size() && j>=0 ;i++,j--){
        total+=min(min(a[i],b[j]),2*min(minu_a,minu_b));
    }
    cout<<total<<nl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        fun();
    }
    return 0;
}
