/*
 * File: SPOJ - FACT2
 * Algorithm: Integer factorization
 * Created Date: Thursday July 30th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
#define int64  __int128
#define lb unsigned __int128
#include<boost/multiprecision/cpp_int.hpp>

namespace mp=boost::multiprecision;
map<int64,int>m1;
inline int64 mulmod(mp::int128_t aa,mp::int128_t bb,mp::int128_t cc){   
	mp::int256_t x = 1;
	x = x*aa*bb%cc;
    return (int64)x;
}
inline int64 power(int64 a, int64 n,int64 mod)
{
    int64 power = a;
    int64 result = 1;
 
    while (n)
    {
        if (n & 1)
            result = mulmod(result , power ,mod);
        power = mulmod(power , power, mod);
        n >>= 1;
    }
    return result;
}
 
bool witness(int64 n, int64 s, int64 d, int64 a)
{
    int64 x = power(a, d, n);
    int64 y;
 
    while (s) {
        y = mulmod(x , x, n);
        if (y == 1 && x != 1 && x != n-1)
            return false;
        x = y;
        --s;
    }
    if (y != 1)
        return false;
    return true;
}

bool is_prime(int64 n)
{
    if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
        return false;
    if (n <= 3)
        return true;
 
    int64 d = n>>1;
    int64 s = 1;
    while (!(d & 1)) {
        d>>=1;
        ++s;
    }
 
    if (n < 1373653)
        return witness(n, s, d, 2) && witness(n, s, d, 3);
    if (n < 9080191)
        return witness(n, s, d, 31) && witness(n, s, d, 73);
    if (n < 4759123141LL)
        return witness(n, s, d, 2) && witness(n, s, d, 7) && witness(n, s, d, 61);
    if (n < 1122004669633LL)
        return witness(n, s, d, 2) && witness(n, s, d, 13) && witness(n, s, d, 23) && witness(n, s, d, 1662803);
    if (n < 2152302898747LL)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11);
    if (n < 3474749660383LL)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13);
    return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13) && witness(n, s, d, 17);
}

int64 gcd(int64 u,int64 v)
{
    int64 shift, diff;
    if (u == 0 || v == 0)
        return u | v;
    for (shift = 0; ((u | v) & 1) == 0; ++shift)
    {
        u >>= 1;
        v >>= 1;
    }
    while ((u & 1) == 0)
        u >>= 1;
       

    do {
        while ((v & 1) == 0)
            v >>= 1;
        if (u < v)
            v -= u;
        else
        {
            diff = u - v;
            u = v;
            v = diff;
        }
        v >>= 1;
    } while (v != 0);
    return u << shift;
}
int64 pollard_brent(int64 N)
{
	int64 g,r,q,x,ys,i,k,cs,xx;
	if(!(N&1)) return 2;
	int64 y = (int64)rand()%(N-1)+1;
	int64 c = (int64)rand()%(N-1)+1;
	int64 m = (int64)rand()%(N-1)+1;
	g = 1;
	r = 1;
	q = 1;
	while(g==1){
		x = y;
		for(i=0; i < r; i++)
		y = (mulmod(y,y,N)+c)%N;
		k = 0;
		while(k < r && g==1){
			ys = y;
			for(i=0;i<min(m,r-k);i++){
				y = (mulmod(y,y,N)+c)%N;
				q = mulmod(q,abs(x-y),N);
			}
			g = gcd(q,N);
			k = k+m;
		}
		r<<= 1;
	}
   if(g==N){ 
   	while(true){ 
   		cs = mulmod(ys,ys,N);
   		ys = (cs+c)%N;
    	g = gcd(abs(x-ys),N);
    	if(g>1)
    	break;
   	}
   }
 return g;
}
void factor(int64 n){
	if(n==1)
		return;

	if(is_prime(n)){
		m1[n]+=1;
		return;
	}
	int64 d=pollard_brent(n);
	factor(d);
	factor(n/d);
}
inline int64 scan(){
        int64 z=0;
        char c;
        do{ c=getchar_unlocked(); } while(c<'0');
        for(;c>='0';c=getchar_unlocked()) z = (z<<3) + (z<<1) + (c&15);
        return z;
    }
void put_uint64(int64 n) {
  char stack[20];
  int top = 0;
  if(n == 0) {
    putchar_unlocked('0');
  } else {
    while(n > 0) {
      stack[top++] = n % 10 + '0';
      n /= 10;
    }
    while(top > 0) {
      putchar_unlocked(stack[--top]);
    }
  }
}
int main()
{
	int t;
	int64 n;
	for(;;)
	{   
		n=scan();
		if(n==0)break;
		map<int64,int>::iterator it1;
		int64 phi1=1;
		factor(n);
		int64 p=1;
		int64 x=0;
		bool flag=false;
		for(it1=m1.begin();it1!=m1.end();it1++){
			put_uint64(it1->first);
			cout<<"^";put_uint64(it1->second);cout<<" ";
	
		}
		printf("\n");
		m1.clear();
		
	}
	return 0;
}