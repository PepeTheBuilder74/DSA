// 4. Max area
class Solution
{
public:
    int dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        // if it is outofbound or already visited return 0
        if (row < 0 || col < 0 || row >= rowSize || col >= colSize || grid[row][col] == 0 || vis[row][col])
        {
            return 0;
        }
        // if it is not visited

        vis[row][col] = 1;
        int area = 0;

        // go to all pos and increase cnt
        area = 1 + dfs(row - 1, col, grid, vis) + dfs(row, col - 1, grid, vis) + dfs(row + 1, col, grid, vis) + dfs(row, col + 1, grid, vis);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int area = 0;
                if (grid[i][j] == 1)
                    area = dfs(i, j, grid, vis);
                ans = max(ans, area);
            }
        }
        return ans;
    }
};