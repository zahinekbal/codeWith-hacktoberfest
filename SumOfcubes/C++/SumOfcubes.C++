
// CPP Program to find sum of cubes of first n natural numbers
#include <bits/stdc++.h>
using namespace std;

int sumofcubes(int n)
{
    return (n * (n + 1) /2) * (n * (n + 1) /2);
}


int main()
{
    int n = 5;
    cout << sumofcubes(n) << endl;
    return 0;
}

/*Output: 225 */
