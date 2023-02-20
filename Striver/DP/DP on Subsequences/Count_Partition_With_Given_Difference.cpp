#include <bits/stdc++.h>
int countPartitions(int n, int d, vector<int> &arr)
{
    const int mod = 1e9 + 7;
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // S1+S2=TotalSum  -1
    // S1-S2=D         -2
    // 1-2=> (2S2=TotalSum - D)
    // Why 1-2 and not 1+2? beacuse then sum might me high since S1 is high and hence will required more space
    // now this is same as target sum where target is (TotalSum-D)/2
    if ((sum - d) & 1)
        return 0;
    if (d > sum)
        return 0;

    int target = (sum - d) / 2;
    vector<int> prev_dp(target + 1, 0);
    // Ways to make zero sum is 1 (dont pick anything)
    prev_dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        vector<int> new_dp = prev_dp;

        for (int j = 0; j <= target; j++)
        {

            // not pick already covered since new_dp=prev_dp , hence we have already copied previous value

            if (arr[i] <= j)
            {
                new_dp[j] = (new_dp[j] + prev_dp[j - arr[i]]) % mod;
            }
        }
        swap(new_dp, prev_dp);
    }
    return prev_dp[target];
}
