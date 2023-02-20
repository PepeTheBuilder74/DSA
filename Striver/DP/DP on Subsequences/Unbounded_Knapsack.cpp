#include <bits/stdc++.h>
int unboundedKnapsack(int n, int maxWeight, vector<int> &value, vector<int> &weight)
{
    vector<int> prev_dp(maxWeight + 1, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> new_dp = prev_dp;
        for (int j = 0; j <= maxWeight; j++)
        {
            // not pick
            new_dp[j] = max(prev_dp[j], new_dp[j]);

            if (j + weight[i] <= maxWeight)
                // new_dp beacuse we can use the same coins many time
                new_dp[j + weight[i]] = max(new_dp[j], new_dp[j] + value[i]);
        }
        swap(new_dp, prev_dp);
    }
    return prev_dp[maxWeight];
}
