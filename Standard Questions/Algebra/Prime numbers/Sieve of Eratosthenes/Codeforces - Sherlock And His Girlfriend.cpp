/*
 * File: Codeforces - Sherlock And His Girlfriend
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Monday July 27th 2020
 * Author: preetam rane
 */


#include<bits/stdc++.h>

using namespace std;


bool is_prime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3;i <= n/i;i += 2)
        if(n % i == 0) return false;
    
    return true;
}

int main()
{
    int n,j=0;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return 0;
    }
    if(n==2){
        cout<<1<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    int arr[n+1];
    for(int i=2;i<=n+1;i++){
        bool t=is_prime(i);
        if(t==1)
            arr[i-2]=1;
        else
            arr[i-2]=2;
    }
    cout<<2<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}