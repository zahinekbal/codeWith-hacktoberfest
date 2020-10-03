///Astalavista Code........~boy_with_no_gf
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Br cout<<endl
#define int long long
#define pb push_back
#define mp make_pair
#define double long double
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define PT(x) cout << (x) << endl
#define PTT(x) cout << (#x) << " is " << (x) << endl; 
#define debug(x) cout<<"~~"<<#x<<" => "<<x<<endl; 
#define lets_go ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int M = 1e9 + 7;
const int N = 2e6 + 10;
const int IM = 1e15 + 37;
const double PI = 3.1415926535897932384;
inline void PP(int n) { cout << n << " ";}
void IN(vector<int>&arr,int n,int x=0){for(int i=x;i<n+x;i++)cin>>arr[i];}
void PV(vi v) { for (int i = 0 ; i < v.size() ; i++) cout << v[i] << " " ; cout << endl;}
void PVR(vi v) { for (int i = v.size()-1 ; i >=0 ; i--) cout << v[i] << " " ; cout << endl;}
void PVV(vii v) {for (int i = 0 ; i < v.size() ; i++) cout << v[i].first << " " << v[i].second << endl;}
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] << " " ; cout << endl;}
void IN(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
// <=================================================================================================================================
// <=================================================================================================================================


void fun(){
    int n,m;cin>>n>>m;
    vi arr(n);
    IN(arr,n);
    int sum=0;
    int i=0;
    int j=0;
    while(j<n){
        i=j;
        // cout<<sum<<" ";
        while(arr[i]<arr[i+1] && i<n-1)
            i++;
        sum+=arr[i];
        // cout<<"added "<<sum<<" ";
        while(arr[i]>arr[i+1] && i<n-1)
            i++;
        if(i!=n-1)
            sum-=arr[i];
            // cout<<" sub "<<sum<<" ";
            // j=i;
        else
            break;
        j=i;
    }
    cout<<sum<<endl;
}

signed  main() {
    lets_go

    int t;
    t=1;
    cin >> t;
    while (t--) {            
         fun();             
    }                        
                            
                            
    return 0;

}
