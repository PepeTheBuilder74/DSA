#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<bool> prev_dp(sum / 2 + 1, false), ;
    prev_dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        vector<bool> new_dp = prev_dp;
        for (int j = 0; j <= sum / 2; j++)
        {
            if (j + arr[i] <= sum / 2)
            {
                new_dp[j + arr[i]] = prev_dp[j] | new_dp[j + arr[i]];
            }
            new_dp[j] = new_dp[j] | prev_dp[j];
        }
        swap(new_dp, prev_dp);
    }
    int ans = sum;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (prev_dp[i])
            ans = min(ans, sum - 2 * i);
    }
    return ans;
}
