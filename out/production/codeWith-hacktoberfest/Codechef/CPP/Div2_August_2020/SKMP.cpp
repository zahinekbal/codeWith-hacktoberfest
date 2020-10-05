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
    string full,req;cin>>full>>req;
    vi freq(26,0);
    vi freq2(26,0);
    for(int i=0;i<full.length();i++){
        freq[full[i]-'a']++;
    }
    for(int i=0;i<req.length();i++){
        freq[req[i]-'a']--;
    }
    freq2=freq;
    // PV(freq);
    string req2=req;
    string s1="";string s2="";
    for(int i=0;i<=26;i++){
        if((req[0]-'a')>i){
        while(freq[i]>0){
            s1+=(char)('a'+i);
            freq[i]--;
        }
        }else{
            req=s1+req;
    for(;i<26;i++){
        while(freq[i]>0){
            freq[i]--;
            req+=(char)('a'+i);
        }
    }
        }
    }for(int i=0;i<=26;i++){
        if((req2[0]-'a')>=i){
        while(freq2[i]>0){
            s2+=(char)('a'+i);
            freq2[i]--;
        }
        }else{
            req2=s2+req2;
        for(;i<26;i++){
        while(freq2[i]>0){
            freq2[i]--;
            req2+=(char)('a'+i);
        }
    }
        }
    }
    cout<<min(req2,req)<<endl;
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
