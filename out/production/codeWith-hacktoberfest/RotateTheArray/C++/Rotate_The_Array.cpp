//Rotate the Array 
//Language: C++

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ar array

#define pb push_back
#define vt vector
#define REP(i,a,b) for(int i = a; i <= b; i++)


using namespace std;

vector<int> rotate(vector<int> vals, int num, int d){//vals = array of integers, num- number of places shift, d=length of array	
	vector<int> ans;
	for(int i  = d-num; i < d; i++){
		ans.pb(vals[i]);
	}
	for(int i = 0; i< d-num; i++){
		ans.pb(vals[i]);
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int rot;
	vector<int> test = {1,2,3,4,5,6};
	cout << "how many rotations do you want: "<<endl;
	cin >> rot;
	vector<int> print = rotate(test,rot,6);
	for(int i =0; i< 6; i++){
		cout << print[i] << " ";
	}
}
