///Astalavista Code........~boy_with_no_gf
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Br cout<<endl
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
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
    int n,k;cin>>n>>k;
    int arr[n+1];
    for(int i=0;i<n;i++) cin>>arr[i];
    int brr[n+1][n+1]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            brr[i][j]=0;
        }
    }
    map<int,int>mad;
    for(int i=0;i<n;i++){
        mad.clear();
        for(int j=i;j<n;j++){
            if(j==0)
                brr[i][j]=0;
            else 
                brr[i][j]=brr[i][j-1];
            
            if(mad.count(arr[j])){
                if(mad[arr[j]]==1){
                    brr[i][j]++;
                }
                brr[i][j]++;
            }
            mad[arr[j]]++;
        }
    }
    int dp[101][1001]={0};
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            dp[i][j]=0;
        }
    }
    for(int i=0;i<n+1;i++)
        dp[1][i]=brr[0][i-1];
    
    for(int i=2;i<=100;i++)
        dp[i][1]=0;
    
    for(int i=2;i<=100;i++){
        for(int j=2;j<=n;j++){
            int total=LLONG_MAX;
            for(int k=1;k<j;k++){
                total=min(total,dp[i-1][k]+brr[k][j-1]);
            }
            dp[i][j]=total;
        }
    }
    int ans=LLONG_MAX;
    for(int i=1;i<=100;i++)
        ans=min(i*k+dp[i][n],ans);

    cout<<ans<<endl;
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
