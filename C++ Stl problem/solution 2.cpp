#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,sum=1,count,A;
		
		cin>>n;
		A=(int)sqrt(n+1);
		count=min((n-A)/(A+1)+A,(n-A-1)/A+A-1);
		cout<<count+1<<"\n";
	
	}
	}
