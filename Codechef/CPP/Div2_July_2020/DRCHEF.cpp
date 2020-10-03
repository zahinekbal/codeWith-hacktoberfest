#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define w(x)             int x;cin >> x;while (x--)
#define rep(d,a,n)       for(int d=a;d<=n;d++)
#define rep_(d,a,n)      for(int d=a;d>=n;d--)
#define nl               "\n"
#define mk(arr,n,type)   type *arr=new type[n];
const int inf=1e18;
const int mod=1e9+7;
void print(vector<int> ptr,int n){
    rep(i,0,n-1){
        cout<<ptr[i]<<" ";
    }cout<<nl;
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
    return;
}

void fun(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    rep(i,0,n-1){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    if(arr[n-1]<=x){cout<<n<<nl;return;}
    auto pt=upper_bound(arr.begin(),arr.end(),(x/2));
    int day=pt-arr.begin();
    int i=pt-arr.begin();
    while(i<n){
        if(arr[i]<=(x/2)){
            x=2*arr[i];
            arr[i]=0;
            day++;
        }else{
            while(true){
                if((x)>=arr[i]){
                    break;
                }else{
                    x*=2;
                    day++;
                }
            }
            x=2*arr[i];
            arr[i]=0;
            day++;
        }
        i++;
    }
    
    cout<<day<<nl;
}


int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    w(t){
        fun();
    }


    return 0;
}
