//Codeforces Round #667 Div(3)
//Rating: 1200
//tags: brute force, math, number theory
//https://codeforces.com/contest/1409/problem/C
#include <bits/stdc++.h>

#define PB push_back
using namespace std;

void TEST(){
	int n,x,y;
	cin >> n >> x >> y;
	int dist = y-x;
	int dunno;
	for(int i = n-1; i > 0; i--){
		if(dist % i == 0){
			dunno = dist / i;
			break;
		}
	}
	vector<int> ans;
	int add = 0;
	for(int i = 0; i< n; i++){
		if(add == 0){
			if(y-(dunno*i) <=0){
				add = 2;
				ans.PB(y+ (dunno));
			}else{
				ans.PB(y-(dunno*i));
			}
		}else{
			ans.PB(y + (dunno*add));
			add++;
		}
	}
	for(int i = 0; i< n; i++){
		cout << ans[i] << " ";
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int i = 0;i < T; i++){
		TEST();
	}
}
