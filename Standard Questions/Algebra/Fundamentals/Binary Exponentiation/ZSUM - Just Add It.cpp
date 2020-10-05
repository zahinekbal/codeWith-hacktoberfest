/*
 * File: ZSUM - Just Add It
 * Algorithm: Binary Exponentiation
 * Created Date: Tuesday July 21st 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

long long bigMod( long long a , long long b , long long m ){
	a %= m ;
	long long res = 1 ;
	while(b>0)
	{
		if(b&1) res = (res*a) % m ;
		a = (a*a) % m ;
		b >>= 1 ; 
	}
	return res ;
}


int main(){
    int n,k,m=10000007;
    while(cin>>n>>k){
        if(n==0 && k ==0) break;
        cout<< ( bigMod(n,k,m) + 2*bigMod(n-1,k,m)+bigMod(n,n,m) + 2*bigMod(n-1,n-1,m) ) % m<<endl;
    }
    return 0;
}
