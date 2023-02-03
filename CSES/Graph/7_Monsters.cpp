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
int dist[1010][1010];
int d[1010][1010];
bool isValid(int x, int y, int steps)
{
    return (x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1 && grid[x][y] != 1) && (dist[x][y] == -1 && (d[x][y] > steps || d[x][y] == -1));
}
bool isValid1(int x, int y)
{
    return (x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1 && grid[x][y] != 1) && (dist[x][y] == -1);
}
int main()
{
    queue<vector<int>> q;
    cin >> n >> m;
    int sx, sy;
    memset(dist, -1, sizeof(dist));
    memset(d, -1, sizeof(d));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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
                grid[i][j] = 0;
                q.push({i, j, 0});
                vis[i][j] = 1;
                d[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto fr = q.front();
        int x = fr[0], y = fr[1], steps = fr[2];
        q.pop();
        for (int mov = 0; mov < 4; mov++)
        {
            int newX = x + dirX[mov];
            int newY = y + dirY[mov];
            if (!isValid1(newX, newY))
                continue;
            if (vis[newX][newY])
                continue;
            vis[newX][newY] = 1;
            d[newX][newY] = d[x][y] + 1;
            q.push({newX, newY, steps + 1});
        }
    }

    memset(vis, 0, sizeof(vis));
    q.push({sx, sy, 1});
    dist[sx][sy] = 0;
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        auto fr = q.front();
        int x = fr[0], y = fr[1], steps = fr[2];
        q.pop();
        for (int mov = 0; mov < 4; mov++)
        {
            int newX = x + dirX[mov];
            int newY = y + dirY[mov];
            if (!isValid(newX, newY, steps))
                continue;
            if (vis[newX][newY])
                continue;
            vis[newX][newY] = 1;
            dist[newX][newY] = dist[x][y] + 1;
            backTrack[newX][newY] = mov;
            q.push({newX, newY, steps + 1});
        }
    }
    bool found = false;
    int ex, ey;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (vis[i][j])
                {
                    ex = i, ey = j;
                    found = true;
                    break;
                }
            }
        }
        if (found)
            break;
    }
    string ans = "";
    if (found)
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
