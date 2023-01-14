#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
int grid[1010][1010];
int vis[1010][1010];
int backTrack[1010][1010];
int n, m;
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
char dirS[] = {'D', 'U', 'R', 'L'};
bool isValid(int x, int y)
{
    return x >= 1 && y >= 1 && x <= n && y <= m && grid[x][y] != 1;
}

int main()
{
    cin >> n >> m;
    int sx, sy, ex, ey;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
                grid[i][j] = 0;
            else if (ch == '#')
                grid[i][j] = 1;
            else if (ch == 'A')
            {
                grid[i][j] = 2;
                sx = i, sy = j;
            }
            else
            {
                grid[i][j] = 3;
                ex = i, ey = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int mov = 0; mov < 4; mov++)
        {
            int newX = x + dirX[mov];
            int newY = y + dirY[mov];
            if (!isValid(newX, newY))
                continue;
            if (vis[newX][newY])
                continue;

            vis[newX][newY] = vis[x][y] + 1;
            backTrack[newX][newY] = mov;
            q.push({newX, newY});
        }
    }
    string ans = "";
    if (vis[ex][ey])
    {
        cout << "YES\n";
        pair<int, int> start = {sx, sy}, end = {ex, ey};

        while (end != start)
        {
            int i = backTrack[end.first][end.second];
            ans.push_back(dirS[i]);
            int newX = end.first - dirX[i], newY = end.second - dirY[i];
            end = {newX, newY};
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        cout << ans << endl;
    }
    else
    {
        cout << "NO\n";
    }
}
