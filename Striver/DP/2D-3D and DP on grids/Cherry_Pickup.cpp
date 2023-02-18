#include <bits/stdc++.h>
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // State: dp(i,col1,col2) Max chocolate collected till (i,col1) and (i,col2)
    // they are both going to be in same row at the same time
    // Transtition: Dp[i][col1][col2]=max(Dp[i-1][col1-x1][col2-x2)])+grid[i][col1]
    // + grid[i][col2] if(col1==col2) add only one time x1 and x2 belongs to {-1,0,1} directions
    // Answer: Maximum of all elements in last row

    // here one more important thing to notice : if we are at 2nd row Alice cant reach more than min(col,row) col and same goes for bob

    int row = grid.size();
    int col = grid[0].size();
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));
    dp[0][0][col - 1] = grid[0][0] + grid[0][col - 1];
    for (int i = 1; i < row; i++)
    {
        // Alice moving from left
        for (int col1 = 0; col1 < min(col, i + 1); col1++)
        {

            // Bob moving form right
            for (int col2 = col - 1; col2 >= max(0, col - i - 1); col2--)
            {

                vector<int> dir = {-1, 0, 1};
                int maxi = INT_MIN;
                for (int x1 : dir)
                {
                    for (int x2 : dir)
                    {
                        if (col1 + x1 >= 0 && col1 + x1 < col && col2 + x2 >= 0 && col2 + x2 < col)
                        {
                            int cnt = grid[i][col1] + grid[i][col2];
                            if (col1 == col2)
                                cnt = grid[i][col1];
                            maxi = max(maxi, dp[i - 1][col1 + x1][col2 + x2] + cnt);
                        }
                    }
                }
                dp[i][col1][col2] = maxi;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < col; j++)
    {
        for (int k = 0; k < col; k++)
        {
            ans = max(dp[row - 1][j][k], ans);
        }
    }
    return ans;
}

// Space Optimized 
#include <bits/stdc++.h> 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
     // State: dp(i,col1,col2) Max chocolate collected till (i,col1) and (i,col2)
     // they are both going to be in same row at the same time
     // Transtition: Dp[i][col1][col2]=max(Dp[i-1][col1-x1][col2-x2)])+grid[i][col1]
     // + grid[i][col2] if(col1==col2) add only one time x1 and x2 belongs to {-1,0,1} directions
     // Answer: Maximum of all elements in last row

     // here one more important thing to notice : if we are at 2nd row Alice cant reach more than min(col,row) col and same goes for bob

     int row=grid.size();
     int col=grid[0].size();
     vector<vector<int>>prev(col,vector<int>(col,0));
     prev[0][col-1]=grid[0][0]+grid[0][col-1];
     for(int i=1;i<row;i++){
         // Alice moving from left
         vector<vector<int>>cur(col,vector<int>(col,0));
         for(int col1=0;col1<min(col,i+1);col1++){

             // Bob moving form right
             for(int col2=col-1;col2>=max(0,col-i-1);col2--){

                vector<int>dir={-1,0,1};
                int maxi=INT_MIN;
                for(int x1:dir){
                    for(int x2:dir){
                       if(col1+x1>=0 && col1+x1<col && col2+x2>=0 && col2+x2<col){
                          int cnt= grid[i][col1]+grid[i][col2];
                          if(col1==col2)cnt=grid[i][col1];
                          maxi=max(maxi,prev[col1+x1][col2+x2]+cnt);
                              
                       }                    
                    }
                }
                cur[col1][col2]=maxi;                   
             }
         }
         swap(cur,prev);
     }
     int ans=0;
     for(int j=0;j<col;j++)
     {
         for(int k=0;k<col;k++){
             ans=max(prev[j][k],ans);
         }
     }
     return ans;
}
