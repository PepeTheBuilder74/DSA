// 3. Number of islands
/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all
surrounded by water.
*/
// DFS
class Solution
{
public:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {

        // we dont necessarily need visited array we can directly change grid[row][col] to 0 because we aint visiting vertices with 0 value .
        int rowSize = grid.size();
        int colSize = grid[0].size();

        // base condition for outer cound and visited array
        if (row < 0 || col < 0 || row >= rowSize || col >= colSize || vis[row][col])
            return;

        // if it is 0 then it is not a land so we dont need to bother
        if (grid[row][col] == '0')
            return;

        // visited
        vis[row][col] = 1;

        // all possible four directions
        dfs(row - 1, col, grid, vis);
        dfs(row + 1, col, grid, vis);
        dfs(row, col - 1, grid, vis);
        dfs(row, col + 1, grid, vis);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int island = 0;
        vector<vector<int>> vis(rowSize, vector<int>(colSize, 0));
        for (int row = 0; row < rowSize; row++)
        {
            for (int col = 0; col < colSize; col++)
            {
                // if it is one then there is atleast 1 island and this dfs will visit all the vertices of that single island in one go
                if (grid[row][col] == '1' && !vis[row][col])
                {
                    dfs(row, col, grid, vis);

                    island++;
                }
            }
        }
        return island;
    }
};

// BFS
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int island = 0;

        // to avoid looping , we can also use this concept for chess

        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // lamda function so to avoid writing function by passing all that unnec. chunk
        // check if it is in bound
        auto check = [&](int row, int col)
        {
            return 0 <= row && row < rowSize && 0 <= col && col < colSize;
        };

        for (int row = 0; row < rowSize; row++)
        {
            for (int col = 0; col < colSize; col++)
            {
                if (grid[row][col] == '1')
                {
                    island++;

                    // visit one island in one go
                    queue<pair<int, int>> pp;
                    pp.push({row, col});

                    while (!pp.empty())
                    {
                        auto q = pp.front();
                        pp.pop();
                        // iterating through all 4 directions
                        for (auto x : directions)
                        {
                            // eg : newRow=0+1 newCol=0+0 for (0,0)
                            int newRow = q.first + x.first;
                            int newCol = q.second + x.second;
                            if (check(newRow, newCol) && grid[newRow][newCol] == '1')
                            {
                                pp.push({newRow, newCol});

                                // to avoid visiting array we are changing 1 to 0 so we won't visit it either way
                                grid[newRow][newCol] = '0';
                            }
                        }
                    }
                }
            }
        }
        return island;
    }
};
