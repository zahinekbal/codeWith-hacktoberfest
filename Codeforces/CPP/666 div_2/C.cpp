#include<bits/stdc++.h>
using namespace std;
	#define author          "Sihare0riginals"
	#define ss       		string 
	#define lli      		long long int
	#define ld       		long double
	#define f        		first
	#define s        		second
	#define all(v)   		v.begin(),v.end()
	#define I(a,i)			memset(a,i,sizeof(a));
	#define pb       		push_back
	#define mp       		make_pair
	#define L(i,start,end)  for(lli i=start;i<=end;i++)
	#define R(i,start,end)  for(lli i=start;i>=end;i--)
	#define ip(n) 			cin>>n;lli ip[n+1];L(i,1,n)cin>>ip[i];
const lli LINF = 1e18,mod=1e9+7;
void Bl0ck_M0mb0();
 
 
signed main()
{
	Bl0ck_M0mb0();
	lli t=1;
	//cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli a[n+1];
		L(i,1,n)
		cin>>a[i];
		if(n==1)        //If single element subtract it since len=1 is multiple of -val
		{
			cout<<"1 1\n"<<-a[1]<<"\n";
			cout<<"1 1\n0\n1 1\n0\n";
		}
		else            //If Length >1 make all elements except last multiple of n by adding val*(n-1)
		{
			cout<<"1 "<<n-1<<"\n";
			L(i,1,n-1)
			{
				cout<<a[i]*(n-1)<<" ";
				a[i]*=n;
			}
			cout<<endl;
			cout<<"1 "<<n<<"\n";    //Take n length so elements from 1 to n-1 can be reduced to 0 since they are multiple of n
			L(i,1,n-1)
			cout<<-a[i]<<" ";
			cout<<0<<" ";
			cout<<endl;
			cout<<n<<" "<<n<<"\n"<<-a[n]<<"\n";  // Reduce the last element as it will be multiple of -1
		}	
	}
	return 0;
}