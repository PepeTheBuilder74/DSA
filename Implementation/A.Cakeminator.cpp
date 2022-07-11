// A. Cakeminator --> https://codeforces.com/problemset/problem/330/A
int row[11], col[11];
void solve()
{
    int r, c;
    cin >> r >> c;
    char arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    int cake = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 'S')
                continue;
            if (row[i] && col[j])
            {
                continue;
            }
            cake++;
        }
    }
    cout << cake << endl;
}