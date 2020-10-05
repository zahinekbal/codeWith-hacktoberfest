/*
 * File: SPOJ - A Conjecture of Paul Erdos
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Sunday July 26th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3;i <= n/i;i += 2)
        if(n % i == 0) return false;
    
    return true;
}

int main(){
    vector<int> v;
    
    for(int i = 1;i * i < 10000000;++i)
        for(int j = 1;j * j * j * j < 10000000;++j)
            if(is_prime(i * i + j * j * j * j))
                v.push_back(i * i + j * j * j * j);
    
    sort(v.begin(),v.end());
    unique(v.begin(),v.end());
    
    int t,n,sz = v.size();
    
    scanf("%d",&t);
    
    while(t--){
        scanf("%d",&n);
        
        if(n == 1) printf("0\n");
        else{
            int l = 0,h  = sz - 1,idx;
            
            while(l < h ){
                idx = (l + h + 1) / 2;
                
                if(v[idx] > n) h = idx - 1;
                else l = idx;
            }
            
            printf("%d\n",l + 1);
        }
    }
    
    return 0;
}