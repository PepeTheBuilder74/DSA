#include <bits/stdc++.h>

long long int calc(vector<int> &arr, int l, int r)
{

    // state: dp[i] Maximum answer till ith index
    // transition: dp[i]=max(dp[i-1],dp[i-2]+arr[i])
    // answer: max(dp[n-1],dp[n-2])
    // dp[n-1] is from 1 to n-1 and dp[n-2] is from 0 to n-2
    int n = arr.size() - 1;
    vector<long long int> dp(n + 2, 0);
    dp[l] = arr[l];
    dp[l + 1] = max(1LL * arr[l + 1], dp[l]);
    for (int i = l + 2; i <= r; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }
    return dp[r];
}
long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n <= 1)
    {
        return valueInHouse[0];
    }
    else if (n <= 2)
    {
        return max(valueInHouse[0], valueInHouse[1]);
    }
    long long ans = calc(valueInHouse, 0, n - 2);
    ans = max(ans, calc(valueInHouse, 1, n - 1));
    return ans;
}