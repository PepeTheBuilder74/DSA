void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // state: dp(i) = min cost to reach i
    // transition: dp(i) = min(dp(i - j) + abs(a[i] - a[i - j])) for j = 1 to k
    // answer: dp(n - 1)
    vector<long long> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
            }
        }
    }
    cout << dp[n - 1] << endl;
}