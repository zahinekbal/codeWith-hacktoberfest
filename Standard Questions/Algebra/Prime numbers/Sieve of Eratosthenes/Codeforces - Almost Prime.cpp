/*
 * File: Codeforces - Almost Prime
 * Algorithm: Sieve of Eratosthenes
 * Created Date: Monday July 27th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

vector<int> findAlmostPrime(size_t n){
	vector<int> result;
	if (n <= 5) { 
		return result;
	}
	result.reserve(n/2);

	vector<size_t> smallest_prime(n+1, 0);
	vector<size_t> primes;
	primes.reserve(n/2);
	for (size_t i = 2; i != n+1; ++i) {
		if (smallest_prime[i] == 0) {
			primes.push_back(i);
			smallest_prime[i] = i;
		}

		for (size_t j = 0; j != primes.size(); ++j ) {
			if (i*primes[j] <= n)
				smallest_prime[i*primes[j]] = primes[j];
		}
	}

	size_t counter = 0;
	for (size_t i = 6; i != n+1; ++i) {
		if (i != smallest_prime[i]) {
			set<size_t> prime_delimiters;
			size_t j = i;
			while(j != 1) {
				prime_delimiters.insert(smallest_prime[j]);
				j /= smallest_prime[j];
			}
			if(prime_delimiters.size() == 2) 
				result.push_back(i);
		}
	}

	return result;
}

int main() 
{
	size_t n;
	cin >> n;
	vector<int> answer = findAlmostPrime(n);
	cout << answer.size();

	return 0;
}
