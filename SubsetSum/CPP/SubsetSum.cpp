//Code for finding if a number can be formed by adding all
// elements of any subset of given list of numbers
// of a given list
#include <bits/stdc++.h>
using namespace std;
bool isSubsetSumPossible(int n, vector<int> &a, int sum)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    int i, j;
    for (i = 0; i <= n; i++)
        dp[i][0] = true;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i - 1])
                dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    int i;
    for (i = 0; i < n; i++)
        cin >> nums[i];
    int sum;
    cin >> sum;
    if (isSubsetSumPossible(n, nums, sum))
        cout << "Subset formation with given sum is possible";
    else
        cout << "Subset formation with given sum is not possible";
    return 0;
}
