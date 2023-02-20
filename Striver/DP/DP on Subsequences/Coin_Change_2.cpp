class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> prev_dp(amount + 1, 1e8);
        prev_dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            vector<int> new_dp = prev_dp;
            for (int j = 0; j <= amount; j++)
            {
                new_dp[j] = min(new_dp[j], prev_dp[j]);
                if (j + 1LL * coins[i] <= amount)
                {
                    // in unbounded take new_dp instead of prev_dp
                    new_dp[j + coins[i]] = min(new_dp[j + coins[i]], new_dp[j] + 1);
                }
            }
            swap(new_dp, prev_dp);
        }
        int ans = prev_dp[amount];
        if (ans == 1e8)
            ans = -1;
        return ans;
    }
};