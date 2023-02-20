class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        // state: dp(i,j) total sum till i
        // transtition: notpick: dp[i][j]=dp[i-1][j]
        // pick: dp[i][j]=dp[i-1][j-arr[i]]

        vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
            if (i == 0)
            {
                if (nums[0] <= sum / 2)
                    dp[0][nums[0]] = true;
                continue;
            }
            for (int target = 1; target <= sum / 2; target++)
            {
                bool notpick = dp[i - 1][target];
                bool pick = false;
                if (nums[i] <= target)
                    pick = dp[i - 1][target - nums[i]];
                dp[i][target] = pick | notpick;
            }
        }
        return dp[n - 1][sum / 2];
    }
};

// space optimized
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        // state: dp(i,j) total sum till i
        // transtition: notpick: dp[i][j]=dp[i-1][j]
        // pick: dp[i][j]=dp[i-1][j-arr[i]]

        vector<bool> prev(sum / 2 + 1, false), cur(sum / 2 + 1, false);
        for (int i = 0; i < n; i++)
        {
            prev[0] = cur[0] = true;
            if (i == 0)
            {
                if (nums[0] <= sum / 2)
                    prev[nums[0]] = true;
                continue;
            }
            for (int target = 1; target <= sum / 2; target++)
            {
                bool notpick = prev[target];
                bool pick = false;
                if (nums[i] <= target)
                    pick = prev[target - nums[i]];
                cur[target] = pick | notpick;
            }
            swap(cur, prev);
        }
        return prev[sum / 2];
    }
};