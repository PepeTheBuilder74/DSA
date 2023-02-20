#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev_dp(maxWeight + 1, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> new_dp = prev_dp;
        for (int j = 0; j <= maxWeight; j++)
        {
            new_dp[j] = max(prev_dp[j], new_dp[j]);
            if (j + weight[i] <= maxWeight)
                new_dp[j + weight[i]] = max(new_dp[j + weight[i]], prev_dp[j] + value[i]);
        }
        swap(new_dp, prev_dp);
    }
    return prev_dp[maxWeight];
}