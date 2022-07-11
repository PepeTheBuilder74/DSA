// A. Cakeminator --> https://codeforces.com/problemset/problem/330/A

// By observation we can see that apples which has both row and col as evil stawberies cant be eaten so we created 1d array of row and coloumn and increase it whenever 
// we came across a evil stawberies
int row[11], col[11];
void solve()
{
    int r, c;
    cin >> r >> c;
    char arr[r][c];
    
    // input matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            
            // if there is a evil stawberry we initialize both row and coln of that i&j
            if (arr[i][j] == 'S')
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    // eating cake 
    int cake = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {   
            
            // whenever there is S or grid with evil on both row and coln of that grid then we dont eat that cake 
            if (arr[i][j] == 'S')
                continue;
            if (row[i] && col[j])
            {
                continue;
            }
            
            //else eat that cake 
            cake++;
        }
    }
    cout << cake << endl;
}
