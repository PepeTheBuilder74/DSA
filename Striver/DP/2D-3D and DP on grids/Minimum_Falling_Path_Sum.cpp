class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        // state: dp(i,j) minimum path sum at (i,j)
        // transition: dp[i][j]=min(dp[i-1][j],d[i-1][j-1],dp[i-1][j+1])
        // answer: minimum of all elements in last row
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        for (int i = 0; i < col; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int ans = INT_MAX;
                if (j > 0)
                    ans = min(ans, dp[i - 1][j - 1]);
                if (j < row - 1)
                    ans = min(ans, dp[i - 1][j + 1]);
                ans = min(ans, dp[i - 1][j]);
                dp[i][j] = ans + matrix[i][j];
            }
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }
};

// Space optimized
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        // state: dp(i,j) minimum path sum at (i,j)
        // transition: dp[i][j]=min(dp[i-1][j],d[i-1][j-1],dp[i-1][j+1])
        // answer: minimum of all elements in last row
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> prev(col, INT_MAX);
        for (int i = 0; i < col; i++)
        {
            prev[i] = matrix[0][i];
        }
        for (int i = 1; i < row; i++)
        {
            vector<int> cur(col, INT_MAX);
            for (int j = 0; j < col; j++)
            {
                int ans = INT_MAX;
                if (j > 0)
                    ans = min(ans, prev[j - 1]);
                if (j < row - 1)
                    ans = min(ans, prev[j + 1]);
                ans = min(ans, prev[j]);
                cur[j] = ans + matrix[i][j];
            }
            swap(cur, prev);
        }

        return *min_element(prev.begin(), prev.end());
    }
};