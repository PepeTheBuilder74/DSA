#include <bits/stdc++.h>
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev_dp(x + 1, 1e8);
    prev_dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> new_dp = prev_dp;
        for (int j = 0; j <= x; j++)
        {
            // not pick
            new_dp[j] = min(new_dp[j], prev_dp[j]);

            // pick
            if (j + num[i] <= x)
            { // new cuz we can use same coins many times
                new_dp[j + num[i]] = min(new_dp[j + num[i]], new_dp[j] + 1);
            }
        }
        swap(prev_dp, new_dp);
    }
    if (prev_dp[x] == 1e8)
        prev_dp[x] = -1;
    return prev_dp[x];
}