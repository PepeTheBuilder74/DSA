#include <bits/stdc++.h>
int frogJump(int n, vector<int> &height)
{
    // state : dp(i)-->minimum energy to reach i from 1
    // transition: dp(i)=min(dp(i-1)+height(i)-height(i-1),dp(i-2)+height(i)-height(i-2))
    // answer : dp[n]
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            dp[i] = min(dp[i], dp[i - j] + abs(height[i - j] - height[i]));
        }
    }
    return dp[n - 1];
}
