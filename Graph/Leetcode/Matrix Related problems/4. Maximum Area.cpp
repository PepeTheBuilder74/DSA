/*695. Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume 
all four edges of the grid are surrounded by water. The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.
*/
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
        // if it is not visited change land to water (acting as a visited array)
        
        vis[row][col] = 1;
        
        // initial area
        int area = 0;

        // go to all 4 directions  and increase area every time it is valid 
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
                // it is already visited if it is water 
                if (grid[i][j] == 1)
                    area = dfs(i, j, grid, vis);
                ans = max(ans, area);
            }
        }
        return ans;
    }
};
