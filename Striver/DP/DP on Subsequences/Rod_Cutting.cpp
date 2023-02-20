int cutRod(vector<int> &price, int n)
{
    vector<int> new_dp(n + 1, 0);
    // Treat total size as total weight and individual cuts as items
    // we dont need to store previous index we can directly store previous index into current index
    new_dp[0] = 0;

    for (int i = 0; i < price.size(); i++)
    {

        // j=maxWeight
        for (int j = 0; j <= n; j++)
        {
            // not pick is already covered since we are storing prev and cur value in same
            // +1 since sizes are 1 based indexing
            if (i + 1 <= j)
            {
                new_dp[j] = max(new_dp[j], new_dp[j - i - 1] + price[i]);
            }
        }
    }
    return new_dp[n];
}