#include <bits/stdc++.h>
int findWays(vector<int> &num, int tar)
{
    // state : dp[i][j]  Number of ways to choose subset as sum = j till index i
    // transition: notpick=dp[i-1][j]
    //             if(j>=a[i]) pick = dp[i-1][j-a[i]]
    //             dp[i][j]=pick+notpick

    // answer dp[n][tar]
    // base: if(arr[0]==0)dp[0][0]=2;
    //       else dp[0][0]=1 and dp[0][arr[0]]=1;
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if (num[0] <= tar)
    {
        dp[0][num[0]] += 1;
    }
    if (num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 1;

        // remember to start from 0 since we can have elements with value 0
        for (int j = 0; j <= tar; j++)
        {
            int notpick = dp[i - 1][j];
            int pick = 0;
            if (num[i] <= j)
            {
                pick = dp[i - 1][j - num[i]];
            }
            dp[i][j] = (pick + notpick);
        }
    }
    return dp[n - 1][tar];
}

// Space Optimized
#include <bits/stdc++.h>
int findWays(vector<int> &num, int tar)
{
    // state : dp[i][j]  Number of ways to choose subset as sum = j till index i
    // transition: notpick=dp[i-1][j]
    //             if(j>=a[i]) pick = dp[i-1][j-a[i]]
    //             dp[i][j]=pick+notpick

    // answer dp[n][tar]
    // base: if(arr[0]==0)dp[0][0]=2;
    //       else dp[0][0]=1 and dp[0][arr[0]]=1;
    const int mod = 1e9 + 7;
    int n = num.size();
    vector<int> prev(tar + 1, 0), cur(tar + 1, 0);
    if (num[0] <= tar)
    {
        prev[num[0]] += 1;
    }
    if (num[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    cur[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int notpick = prev[j];
            int pick = 0;
            if (num[i] <= j)
            {
                pick = prev[j - num[i]];
            }
            cur[j] = (pick + notpick) % mod;
        }
        swap(prev, cur);
    }
    return prev[tar] % mod;
}
