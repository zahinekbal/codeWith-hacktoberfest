///Astalavista Code........~boy_with_no_gf
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Br cout<<endl
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define mk make_pair
#define allr(v) v.rbegin(),v.rend()
#define PT(x) cout << (x) << endl
#define PTT(x) cout << (#x) << " is " << (x) << endl; 
#define lets_go ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int M = 1e9 + 7;
const int N = 2e6 + 10;
const int IM = 1e15 + 37;
const double PI = 3.1415926535897932384;
inline void PP(int n) { cout << n << " ";}
void PV(vi v) { for (int i = 0 ; i < v.size() ; i++) cout << v[i] << " " ; cout << endl;}
void PVV(vii v) {for (int i = 0 ; i < v.size() ; i++) cout << v[i].first << " " << v[i].second << endl;}
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] << " " ; cout << endl;}
void IN(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
// <=================================================================================================================================
// <=================================================================================================================================


void fun(){
    int n;string ass;cin>>n>>ass;
    vi odd_odd;
    vi odd_even;
    vi even_odd;
    vi even_even;
    for(int i=0;i<n;i++){
        if((i+1)&1){
            if((ass[i]-'0')&1){
                odd_odd.pb(ass[i]-'0');
            }else{
                odd_even.pb(ass[i]-'0');
            }
        }else{
            if((ass[i]-'0')&1)
                even_odd.pb(ass[i]-'0');
            else
            {
                even_even.pb(ass[i]-'0');
            }
        }
    }
    if(n&1){
        // PTT(n);
        if(odd_even.size()<=n/2)
            cout<<1<<endl;
        else
        {
            cout<<2<<endl;
        }
    }
    else{
        // PTT(n);
        if(even_odd.size()<=n/2-1){
            cout<<2<<endl;
        }else{
            cout<<1<<endl;
        }
    }
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