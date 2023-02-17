class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        // state: dp(i,j) minimum path sum at (i,j)
        // transition: dp[i][j]=min(dp[i-1][j],d[i-1][j-1])
        // answer: minimum of all elements in last row
        int row = triangle.size();
        int col = triangle.back().size();
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                int ans = INT_MAX;
                ans = min(ans, dp[i - 1][j]);
                if (j > 0)
                    ans = min(ans, dp[i - 1][j - 1]);
                dp[i][j] = ans + triangle[i][j];
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};

// Space optimized
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        // state: dp(i,j) minimum path sum at (i,j)
        // transition: dp[i][j]=min(dp[i-1][j],d[i-1][j-1])
        // answer: minimum of all elements in last row
        int row = triangle.size();
        int col = triangle.back().size();
        vector<int> prev(1);
        prev[0] = triangle[0][0];
        for (int i = 1; i < row; i++)
        {
            vector<int> cur(triangle[i].size() + 1, INT_MAX);
            for (int j = 0; j < triangle[i].size(); j++)
            {
                int ans = INT_MAX;
                if (j < prev.size())
                    ans = min(ans, prev[j]);
                if (j > 0)
                    ans = min(ans, prev[j - 1]);
                cur[j] = ans + triangle[i][j];
            }
            swap(prev, cur);
        }
        return *min_element(prev.begin(), prev.end());
    }
};