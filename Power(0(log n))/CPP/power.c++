// power A method to compute base^exp in O(log(ex))
long long power(long long x, long long n)
{
	long long res = 1;

	while (n > 0) {
		if (n & 1)
      res = (res * x);

		x = (x * x);

		n = n >> 1;
	}

	return res;
}

/*
Explaination:
  x^n = (x * x) ^ (n/2) if n is even
  x^n = x * x^(n-1) = x * (x * x) ^ (n-1/2) if n is odd

  This will divide n by 2 every iteration and thus it has
  a time complexity of O(log(n))

Usage:
  power(2, 4) -> 16
  power(2, 5) -> 32
  power(2, 0) -> 1
  power(2, 1) -> 2

Example: https://ideone.com/zaOrI4
*/
