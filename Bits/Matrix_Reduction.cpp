// Matrix Reducing
// https://atcoder.jp/contests/abc264/tasks/abc264_c

// editor: https://atcoder.jp/contests/abc264/editorial/4595
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define ar array
const int MxN = 2e5;
ar<int, 2> v[MxN];

int main()
{

    // taking input
    int h1, w1, h2, w2;
    cin >> h1 >> w1;
    vector<vector<int>> v1(h1, vector<int>(w1, 0));
    rep(i, h1)
    {
        rep(j, w1)
        {
            cin >> v1[i][j];
        }
    }
    cin >> h2 >> w2;
    vector<vector<int>> v2(h2, vector<int>(w2, 0));
    rep(i, h2)
    {
        rep(j, w2)
        {
            cin >> v2[i][j];
        }
    }

    // all subset of rows
    for (int i = 0; i < (1 << h1); i++)
    {
        // all subset of columns
        for (int j = 0; j < (1 << w1); j++)
        {

            // temporary vectors to store which rows to take and which columns to take
            vector<int> rvec, cvec;
            for (int row = 0; row < h1; row++)
            {

                // if bit is set then take that row
                if (i & (1 << row))
                {
                    rvec.push_back(row);
                }
            }
            for (int col = 0; col < w1; col++)
            {

                // if bit is set then take that column
                if (j & (1 << col))
                {
                    cvec.push_back(col);
                }
            }

            // if size of both vectors are not equal to size of matrix 2 then continue
            if (rvec.size() != h2 || cvec.size() != w2)
            {
                continue;
            }

            // check if both matrix are equal or not
            bool match = true;
            for (int i = 0; i < h2; i++)
            {
                for (int j = 0; j < w2; j++)
                {
                    if (v1[rvec[i]][cvec[j]] != v2[i][j])
                    {
                        match = false;
                        break;
                    }
                }
            }

            // if both matrix are equal then print yes and return
            if (match)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}