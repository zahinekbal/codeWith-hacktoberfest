#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PI 3.14159265358979323

int main()
{
	int n, j = 0;
    cin>>n;
	int arr[n];
	double sum = 0;

	for (int i = 0;i < n; i++) {
        cin>>arr[i];
    }

	sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--)
    {
        if(!(j%2))sum += arr[i] * arr[i] * PI;
        else sum -= arr[i] * arr[i] * PI;
        j++;
    }
    cout << fixed << setprecision(10) << sum;
return 0;
}
