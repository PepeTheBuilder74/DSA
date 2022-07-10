/* 1. Flood fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.
*/

void dfs(int row, int coloumn, int initialColour, int finalColour, vector<vector<int>> &matrix)
{
    int totalRow = matrix.size();
    int totalCol = matrix[0].size();

    // out of bounds condition
    if (row < 0 || coloumn < 0 || row >= totalRow || coloumn >= totalCol)
        return;

    //  visited array
    if (matrix[row][coloumn] != initialColour || matrix[row][coloumn] == finalColour)
        return;

    // change the array to new array
    matrix[row][coloumn] = finalColour;

    // all 4 direction traversal
    dfs(row - 1, coloumn, initialColour, finalColour, matrix);
    dfs(row, coloumn - 1, initialColour, finalColour, matrix);
    dfs(row + 1, coloumn, initialColour, finalColour, matrix);
    dfs(row, coloumn + 1, initialColour, finalColour, matrix);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initialColor = image[sr][sc];

    // will fail when all elements and finalColor is equal to 0 (stack overflow ) thats why we are using this cond.
    if (initialColor != color)
    {
        dfs(sr, sc, initialColor, color, image);
    }
}

// Complexty: Space->O(n*m) , Time: O(n*m)