#include <iostream>
using namespace std;

int power(int x, int n)
{
	// Base case
	if(n==1)
		return x;
		
	if(n%2==0)
		return power(x*x,n/2);
	else
		return x * power(x*x,n/2);
}

int main() {
	int x,n;
	cin >> x >> n;
	int ans = power(x,n);
	cout << ans;
	return 0;
}