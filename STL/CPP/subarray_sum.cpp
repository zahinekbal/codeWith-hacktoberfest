// Given an unsorted array A of size N of non-negative integers
// find a continuous sub-array which adds to a given number S.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,s;
	    cin>>n>>s;
	    int arr[n];
	    
	    for(int i = 0; i < n; i++) cin>>arr[i];
	    
	    deque<pair<int,int> > dq;
	    int curr_sum = 0,f = 0; 
	    
	    for(int i = 0; i < n; i++){
	        
	        dq.push_back({arr[i],i});
	        curr_sum += arr[i]; 
	        
	        while(curr_sum > s && !dq.empty()){
	            curr_sum -= dq.front().first;
	            dq.pop_front();
	        }
	        
	        
	        
	        if(curr_sum == s){
	            cout<<dq.front().second + 1<<" "<<dq.back().second + 1<<endl;
	            f = 1;
	            break;
	        }
	    }
	    if(f == 0){
	        cout<<-1<<endl;
	    }
	}
	return 0;
}