class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // state dp[i][j] -> minimum cost to reach (i,j) from (0,0)
        // transition dp[i][j]=grid[i][j]+ min(dp[i-1][j],dp[i][j-1])
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[0][0];
                    continue;
                }
                else
                {
                    int down = 0, right = 0;
                    if (i > 0)
                        down = dp[i - 1][j] + grid[i][j];
                    else
                        down = 1e9;
                    if (j > 0)
                        right = dp[i][j - 1] + grid[i][j];
                    else
                        right = 1e9;
                    dp[i][j] = min(right, down);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};

// Space optimized solution
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // state dp[i][j] -> minimum cost to reach (i,j) from (0,0)
        // transition dp[i][j]=grid[i][j]+ min(dp[i-1][j],dp[i][j-1])
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> cur(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    cur[j] = grid[0][0];
                    continue;
                }
                else
                {
                    int down = 0, right = 0;
                    if (i > 0)
                        down = prev[j] + grid[i][j];
                    else
                        down = 1e9;
                    if (j > 0)
                        right = cur[j - 1] + grid[i][j];
                    else
                        right = 1e9;
                    cur[j] = min(right, down);
                }
            }
            swap(cur, prev);
        }

        return prev[m - 1];
    }
};