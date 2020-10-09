#include <bits/stdc++.h>

using namespace std;

const int N_BOUND = 10000000;

/*
 * Finds prime numbers up to and including n
 */
void sieveOfEratosthenes (const int n, vector<int>& primes)
{
    vector<bool> isPrime(n + 1, true); // bound on n is inclusive, that's why isPrime[n] needs to be valid
    primes.clear();

    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);

            for(int j = i + i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    /*
     * Sample code that uses Sieve of Eratosthenes to find and print the prime
     * numbers up to a value.
     *
     * Input format:
     * T -> number of test cases to try
     * For each test case:
     *     n -> bounding value - sieve will find primes in range [0, n]
     */
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        if(N < 0 || N > N_BOUND)
        {
            cout << "INPUT INVALID:" << endl;
            cout << "\tN must be a non-negative value smaller than " << N_BOUND << endl;
            cout << "Skipping test case #" << t << "..." << endl;
            continue;
        }

        vector<int> primes;
        sieveOfEratosthenes(N, primes);
        if(primes.size() > 0)
        {
            cout << "PRIMES FOUND FOR TEST CASE #" << t << ':' << endl;
            for(unsigned int i = 0; i < primes.size(); ++i)
            {
                cout << primes[i] << endl;
            }
        }
        else
        {
            cout << "NO PRIMES WERE FOUND FOR TEST CASE #" << t << endl;
        }
    }

    return 0;
}

