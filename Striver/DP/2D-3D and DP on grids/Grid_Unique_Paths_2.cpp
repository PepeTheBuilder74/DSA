class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // state: dp[i][j] Number of paths till i,j
        // transition : dp[i][j]=dp[i-1][j]+dp[i][j-1] and dp[i][j]=0 if obstacleGrid[i][j]=1
        // answer: dp[m-1][n-1]
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        if (obstacleGrid[0][0])
            return 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = 1;
                    continue;
                }
                if (obstacleGrid[i][j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    int right = 0, down = 0;
                    if (i > 0)
                        down = dp[i - 1][j];
                    if (j > 0)
                        right = dp[i][j - 1];
                    dp[i][j] = down + right;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Space optimized solution
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);
        if (obstacleGrid[0][0])
            return 0;
        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    cur[0] = 1;
                    continue;
                }
                if (obstacleGrid[i][j])
                {
                    cur[j] = 0;
                }
                else
                {
                    int right = 0, down = 0;
                    if (i > 0)
                        down = prev[j];
                    if (j > 0)
                        right = cur[j - 1];
                    cur[j] = down + right;
                }
            }
            swap(cur, prev);
        }
        return prev[n - 1];
    }
};