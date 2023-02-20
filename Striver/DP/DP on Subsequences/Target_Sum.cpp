#include <bits/stdc++.h>
int targetSum(int n, int target, vector<int> &arr)
{
    unordered_map<int, int> prev_dp, new_dp;
    prev_dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        // visit valid states only
        for (auto &p : prev_dp)
        {
            int u = p.first, v = p.second;
            new_dp[u + arr[i]] += v;
            new_dp[u - arr[i]] += v;
        }
        swap(prev_dp, new_dp);

        // if we dont clear then we might face over-counting
        new_dp.clear();
    }
    return prev_dp[target];
}
