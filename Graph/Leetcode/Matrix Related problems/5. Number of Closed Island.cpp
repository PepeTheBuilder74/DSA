// 1254. Number of Closed Islands
/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an
island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.
*/
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &grid)
    {
        int maxRow = grid.size();
        int maxCol = grid[0].size();

        // base condition
        if (row < 0 || col < 0 || row >= maxRow || col >= maxCol || grid[row][col] == 1)
        {
            return;
        }

        grid[row][col] = 1;

        // all 4 direction
        dfs(row - 1, col, grid);
        dfs(row + 1, col, grid);
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int maxRow = grid.size();
        int maxCol = grid[0].size();
        int totIsland = 0;
        for (int row = 0; row < maxRow; row++)
        {
            for (int col = 0; col < maxCol; col++)
            {
                if (row == 0 || col == 0 || col == maxCol - 1 || row == maxRow - 1)
                {
                    dfs(row, col, grid);
                }
            }
        }
        for (int row = 0; row < maxRow; row++)
        {
            for (int col = 0; col < maxCol; col++)
            {
                if (grid[row][col] == 0)
                {
                    dfs(row, col, grid);
                    totIsland++;
                }
            }
        }
        return totIsland;
    }
};
