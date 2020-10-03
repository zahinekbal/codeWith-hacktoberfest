#include <bits/stdc++.h>
#define ll long long int
#define LIMIT 2000000000
using namespace std;
ll X[100002];
ll Y[100002];
double xdif[100002];
double ydif[100002];
pair<double,double>ans ; 

ll a ,b ; 

bool checkans(){
    if(ans.first > LIMIT || ans.second <-LIMIT){
        return false ; 
    }

   /* if(ans.second -ans.first > 1){
        a = ceil(ans.first) ;
        if(ceil(ans.first) == floor(ans.first)){
            a++ ; 
        }
        b = 1 ; 
    }

    else if(ans.second-ans.first == 1){
        if(ceil(ans.first) == floor(ans.first)){
            a = ans.first*2+1 ; 
            b = 2 ; 
        }
        else{
            a= ceil(ans.first);
            b=1;
            
        }
    }

    else{
        b = ceil(1/(ans.second-ans.first));
        if(ceil(ans.first*b) == floor(ans.first*b)){
            if(ans.second*b-ans.first*b == 1){
                b++ ; 
            }
        }

        a = ceil(ans.first*b) ; 
        if(ceil(ans.first*b) == floor(ans.first*b)){
            a++ ; 
        }
    }
    */
    if(ans.second -ans.first >1){
        a = floor(ans.first)+1 ;
            b = 1 ; 
    }

    else{
        b = ceil(2/(ans.second-ans.first));
        a = floor(ans.first*b)+1 ; 
       }
       
    if(a > LIMIT || a< -LIMIT || b > LIMIT || b <-LIMIT){
        return false ; 
    }
  
    return true ;  
}

bool findmin(pair<double, double>range ,int ind , bool sign , int count ,  int n){
      
      if(range.first > LIMIT || range.second <-LIMIT){
          return false ;
      }

     if(ind > n){
       ans = range ;  
       if(checkans() == 1){
         return true ; 
       }
       return false ; 
    }
     
    double a = 1;

    if(xdif[ind] != 0) {
       a = -ydif[ind]/xdif[ind] ;
    }

    if(sign == 0){

        if(xdif[ind] == 0){
            if(ydif[ind] <= 0){
                 return false ; 
            }
        }
         
        else if(xdif[ind] < 0){

            if(range.first >= a){
              return false ; 
            }  
           
            else if(a > range.first && a < range.second){
               range.second = a ; 
            }            
        }

        else {

            if(a >= range.second){
                return false ; 
            }
            else if(a > range.first && a < range.second){
                range.first = a ; 
            }
        }
    }

    else{
     
        if(xdif[ind] == 0){
            if(ydif[ind] >=0){
               return false ; 
            }
        }

        else if(xdif[ind] < 0){ 
          
          if(a >= range.second){
              return false ; 
          }

          else if(a > range.first && a<range.second){
              range.first = a ; 
          }

        }

        else {

            if(range.first >= a){
                return false ; 
            }

            else if(a > range.first && a < range.second){
                range.second = a ; 
            }
        }
    }
    
    if(findmin(range , ind+1 , sign , count , n) == 1){
        return true ; 
    }
    
    if(count+1 <= 2){
       if(findmin(range, ind+1 , !sign , count+1 , n) == 1){
        return true ; 
       }
    }
     
    return false ;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; 
    cin>>t ; 

    while(t--){

        int n ; 
        cin>>n ; 
        
        cin>>X[1]>>Y[1] ; 
        for(int i=2 ; i<=n ; i++){
            cin>>X[i]>>Y[i] ; 
            xdif[i-1] = X[i]-X[i-1];
            ydif[i-1] = Y[i]-Y[i-1];
        }

        xdif[n] = X[1]-X[n];
        ydif[n] = Y[1]-Y[n];

        ll a , b ; 
        
        pair<double, double>range = {LLONG_MIN ,LLONG_MAX};
        
        
        if(findmin(range , 1 , 0 , 0 , n) || findmin(range , 1 , 1 , 0, n)){
            
            a = ::a ;
            b = ::b ;
        }
         
        else{
            a = 0 ; 
            b = 0 ; 
        }

        cout<<a<<" "<<b<<"\n";                

    }
}