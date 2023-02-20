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
class Solution
{
public:
#define ll long long int
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    ll getMask(int n)
    {
        ll ans = 0;
        for (int i = 0; i < 10; i++)
        {
            if (n % prime[i] == 0)
            {
                ans |= (1LL << i);
                int cnt = 0;
                while (n % prime[i] == 0)
                {
                    n /= prime[i];
                    cnt++;
                }
                if (cnt >= 2)
                    return -1;
            }
        }
        return ans;
    }
    int squareFreeSubsets(vector<int> &nums)
    {

        int n = nums.size();
        const int mod = 1e9 + 7;
        vector<vector<ll>> dp(n + 1, vector<ll>((1 << 10) + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            ll cur_mask = getMask(nums[i - 1]);
            if (cur_mask == -1)
                continue;
            for (ll mask = 0; mask < (1LL << 10); mask++)
            {
                if (cur_mask & mask)
                {
                    dp[i][mask] = dp[i - 1][mask];
                    continue;
                }
                ll notpick = dp[i - 1][mask];
                ll pick = 0;
                pick = dp[i - 1][cur_mask | mask];
                dp[i][mask] = (pick + notpick) % mod;
            }
        }
        ll ans = 0;
        for (int i = 0; i < (1 << 10); i++)
        {
            ans = (ans + dp[n][i]) % mod;
        }
        ans -= 1;
        if (ans < 0)
            ans += mod;
        return ans;
    }
};