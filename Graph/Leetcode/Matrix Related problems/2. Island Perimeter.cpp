/* 2 . island perimeter
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more
connected land cells). The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side
length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 */
class Solution
{
public:
    int dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        // if it reaches water or out of bound means perimeter increases by 1
        if (row < 0 || col < 0 || row >= rowSize || col >= colSize || grid[row][col] == 0)
        {
            return 1;
        }
        // if already visited return 0
        if (vis[row][col])
        {
            return 0;
        }

        vis[row][col] = 1;
        int per = 0;

        // go to all pos and increase cnt
        per += dfs(row - 1, col, grid, vis);
        per += dfs(row, col - 1, grid, vis);
        per += dfs(row + 1, col, grid, vis);
        per += dfs(row, col + 1, grid, vis);
        return per;
    }
    
   

    int islandPerimeter(vector<vector<int>> &grid)
    {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                //  in question this is given only 1 island is there from this thats why return directly

                if (grid[i][j] == 1)
                    return dfs(i, j, grid, vis);
            }
        }
        return 0;
    }
};
   // Time complexty : O(m*n , Space Complexity: O(m*n)
