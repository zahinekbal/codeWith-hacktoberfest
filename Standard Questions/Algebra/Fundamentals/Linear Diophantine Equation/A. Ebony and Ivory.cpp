/*
 * File: A. Ebony and Ivory
 * Algorithm: Linear Diophantine Equation
 * Created Date: Thursday July 23rd 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>
using namespace::std;

int gcd(int a, int b){
	if(a<b) return gcd(b,a);
	return b==0?a:gcd(b,a%b);
}

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int mcd = gcd(a,b);
	if(c%mcd == 0){
		int k = 0;
		while(a*k<=c){
			if((c-a*k)%b==0){
				cout<<"Yes"<<endl;
				return 0;
			}
			k++;
		}
	}
	cout<<"No"<<endl;
	return 0;
}
