#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    vector<int> dp(n, 0);
    int i;
    for (i = 0; i < n; i++)
        cin >> nums[i];
    if (n == 0)
        cout << 0;
    else if (n == 1)
        cout << nums[0];
    else if (n == 2)
        cout << max(nums[0], nums[1]);
    else
    {
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (i = 2; i < n; i++)
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        cout << dp[n - 1];
    }
    return 0;
}
