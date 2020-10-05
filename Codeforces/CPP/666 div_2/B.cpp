
// Problem : B. Power Sequence
// Contest : Codeforces - Codeforces Round #666 (Div. 2)
// URL : https://codeforces.com/contest/1397/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define PTT(x) cout << (#x) << " is " << (x) << endl
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
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] << ' ' ; cout << endl;}
void IN(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}

// <=================================================================================================================================
// <=================================================================================================================================

void fun(){
	int n;cin>>n;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	sort(all(arr));
	int ans=0;
	int val=ceil(pow(arr[n-1],1.0/(n-1)));
	if(arr[0]!=1){
		ans+=arr[0]-1;
		arr[0]=1;
	}
	for(int i=1;i<n;i++){
		ans+=abs(arr[i]-pow(val,i));
	}
	cout<<ans;
}

signed  main() {
    lets_go

    int t;
    t=1;
//    cin >> t;
    while (t--) {

    fun();

    }



    return 0;

}
