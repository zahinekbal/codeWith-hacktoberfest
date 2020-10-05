/*
 * File: SPOJ - Binary Sequence of Prime Numbers
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Tuesday July 28th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

unsigned prime[5899179],numPrime;
unsigned binary[150000007];
const int L1D_CACHE_SIZE = 37768;

inline void segmented_sieve(int limit, int segment_size = L1D_CACHE_SIZE){
  int sqrt = (int) std::sqrt((double) limit);
  int count = (limit < 2) ? 0 : 1;
  int s = 2;
  int n = 3;

  vector<char> segment(segment_size);

  vector<char> is_prime(sqrt + 1, 1);
  for (unsigned i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;

  vector<unsigned> primes;
  vector<unsigned> next;
  int p=2;
  for (unsigned low = 0; low <= limit; low += segment_size){
    fill(segment.begin(), segment.end(), 1);
  

    int high = min(low + segment_size - 1, (unsigned)limit);


    for (; s * s <= high; s++)
      if (is_prime[s]){
        primes.push_back((int) s);
        next.push_back((int)(s * s - low));
      }

    for (size_t i = 1; i < primes.size(); i++){
      int j = next[i];
      for (unsigned k = (primes[i]<<1); j < segment_size; j += k)
        segment[j] = 0;
      next[i] = j - segment_size;
    }
    prime[1]=2;
    prime[2]=3;
    for (; n <= high; n += 2)
      if (segment[n - low]) 
      {   prime[p++]=n;
      }
  }numPrime=p;
}
int b=0;

void compute(){   
	unsigned sum=0,v=0,c=0,k=0,ind=1;
	for(unsigned i=1;i<numPrime;i++){
		int j, flag = 0;
	    int num;
		num=prime[i];
		for (j=0; j < 32; j++) {
         if (num < 0) {
            b+=1;binary[ind++]=b;
            flag = 1;
        } else if (flag){binary[ind++]=b;}
        num =  num << 1;
      }
	}
}

inline unsigned scan(){
        unsigned z=0;
        char c;
        do{ c=getchar_unlocked(); } while(c<'0');
        for(;c>='0';c=getchar_unlocked()) z = (z<<3) + (z<<1) + (c&15);
        return z;
}

inline void put_uint(unsigned n) {
  char stack[15];
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
  putchar_unlocked('\n');
}

int main()
{
	unsigned tc,n;
	int limit = 101865020;
    unsigned size = L1D_CACHE_SIZE;
    segmented_sieve(limit, size);
	compute();
	scanf("%d",&tc);
	while(tc--)
	{
		n=scan();
		put_uint(binary[n]);
	}
}