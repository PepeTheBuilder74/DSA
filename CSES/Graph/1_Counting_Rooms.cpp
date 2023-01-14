#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
int grid[1001][1001];
int n, m;
void dfs(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m || grid[i][j] == 1)
        return;
    grid[i][j] = 1;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
                grid[i][j] = 0;
            else
                grid[i][j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == 0)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
