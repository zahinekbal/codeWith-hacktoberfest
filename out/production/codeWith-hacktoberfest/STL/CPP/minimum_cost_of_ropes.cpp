// Question //
/**
Given n ropes of different lengths, we need to connect these ropes into one rope.
We can connect only 2 ropes at a time. The cost required to connect 2 ropes is equal
 to sum of their lengths. The length of this connected rope is also equal to the sum
of their lengths. This process is repeated until n ropes are connected into a single
rope. Find the min possible cost required to connect all ropes.

Input : ropes = [8, 4, 6, 12]
Output: 58
Explanation: The optimal way to connect ropes is as follows
1. Connect the ropes of length 4 and 6 (cost is 10). Ropes after connecting: [8, 10, 12]
2. Connect the ropes of length 8 and 10 (cost is 18). Ropes after connecting: [18, 12]
3. Connect the ropes of length 18 and 12 (cost is 30).
Total cost to connect the ropes is 10 + 18 + 30 = 58

**/
// use of C++ STL priority queue //
// Solution //
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    ll a[n];
	    priority_queue<ll> p; // STL priority queue
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        p.push(-a[i]); // inserting negative value to act as min priority queue
	    }
	    ll cost=0;
	    while(p.size()>1)
	    {
	        ll a=p.top();
	        p.pop();
	        a=-a;
	        ll b=p.top();
	        b=-b;
	        p.pop();
	        cost+=a+b;
	        p.push(-(a+b));
	    }
	    cout<<cost<<endl;
	    //priority_queue<int> p;
	}
	return 0;
}
