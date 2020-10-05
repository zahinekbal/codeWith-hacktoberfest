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

int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    int inv_count = 0; 
  
    int i = left; 
    int j = mid;  
    int k = left; 
    while ((i <= mid - 1) && (j <= right)) 
    { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
      while (j <= right) 
        temp[k++] = arr[j++]; 
     for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) 
    { 
        mid = (right + left)/2; 
        inv_count  = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid+1, right); 
        inv_count += merge(arr, temp, left, mid+1, right); 
    } 
  
    return inv_count; 
} 
int countSwaps(int arr[], int n) 
{ 
    int temp[n]; 
    return _mergeSort(arr, temp, 0, n - 1); 
} 
void fun(){
    int n;cin>>n;
    int req=(n*(n-1))/2;
    req--;
    int arr[n];
    IN(arr,n);
    int pos=countSwaps(arr,n);
    if(pos<=req){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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
