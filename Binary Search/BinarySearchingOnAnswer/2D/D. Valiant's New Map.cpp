// D. Valiant's New Map
bool check(vector<vector<int>> &arr, int mid)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    rep(i, n)
    {
        rep(j, m)
        {
            // 2 d prefix sum
            dp[i + 1][j + 1] = dp[i + 1][j + 1] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + (arr[i][j] >= mid);
        }
    }
    for (int i = mid; i <= n; i++)
    {
        for (int j = mid; j <= m; j++)
        {
            if (dp[i][j] - dp[i - mid][j] - dp[i][j - mid] + dp[i - mid][j - mid] == mid * mid)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // remove for interactive problems
    ios_base::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        rep(i, n)
        {
            rep(j, m)
            {
                cin >> arr[i][j];
            }
        }
        int low = 1, high = min(n, m);
        int ans = 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(arr, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
// extra problems of this type
// 1. https://atcoder.jp/contests/abc203/tasks/abc203_d?lang=en. 
