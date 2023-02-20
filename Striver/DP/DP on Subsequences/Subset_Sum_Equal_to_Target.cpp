#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // State: dp(i,j)   Element picked till index i with sum j
    // Transition: dp(i,j)= pick: dp[i][j]=dp[i-1][j-arr[i]]
    //                      not pick: dp[i][j]=dp[i-1][j]
    // answer: dp[n][k] is true or not

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
        if (i == 0)
        {
            if (arr[0] <= k)
                dp[0][arr[0]] = 1;
            continue;
        }
        for (int target = 1; target <= k; target++)
        {
            bool notpick = dp[i - 1][target];
            bool pick = 0;
            if (target - arr[i] >= 0)
                pick = dp[i - 1][target - arr[i]];

            dp[i][target] = pick | notpick;
        }
    }
    return dp[n - 1][k];
}

// Space Optimized
#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // State: dp(i,j)   Element picked till index i with sum j
    // Transition: dp(i,j)= pick: dp[i][j]=dp[i-1][j-arr[i]]
    //                      not pick: dp[i][j]=dp[i-1][j]
    // answer: dp[n][k] is true or not
    vector<bool> prev(k + 1, false);
    for (int i = 0; i < n; i++)
    {
        vector<bool> cur(k + 1, false);
        cur[0] = 1;
        if (i == 0)
        {
            if (arr[0] <= k)
                prev[arr[0]] = 1;
            prev[0] = 1;
            continue;
        }
        for (int target = 1; target <= k; target++)
        {
            bool notpick = prev[target];
            bool pick = 0;
            if (target - arr[i] >= 0)
                pick = prev[target - arr[i]];

            cur[target] = pick | notpick;
        }
        swap(cur, prev);
    }
    return prev[k];
}
