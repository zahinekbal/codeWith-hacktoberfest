
/*
 *	Code for modular exponentiation 
 *	Time complexity : O(n*log(n))
 */

#include<bits/stdc++.h>
using namespace std;

// This function returns value of (x^y)%mod. 
int power(int x, int y, int mod)
{
	int answer = 1; // Initialise the answer

	x = x % mod;

	if(x == 0) return 0; // If x is divisible by mod
	
	while(y > 0)
	{
		if(y % 2 == 1)	// If y is odd multiply x with answer
		{
			answer = (answer*x) % mod;
		}

		y /= 2; // reduce the value of y
		x = (x*x) % mod; // increment the value of x
	}

	return answer;
}


// Main function
int main()
{
	int x = 2, y = 10, mod = 1000000007;
	int result = power(x, y, mod);
	cout << result << '\n';

	return 0;
}
