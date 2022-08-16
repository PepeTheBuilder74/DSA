#include <bits/stdc++.h>
using namespace std;

/*1. Knapsack 0-1

                                                         Based on pick and not pick
TC->
SC->
ASC->

*/

class Solution
{
public:
    int dp[1001][1001];

    int helper(int index, int wt_left, int val[], int wt[])
    {
        if (index == 0)
        {
            // pick all the remaining items of same vakue
            return wt_left / wt[0] * val[0];
        }

        if (dp[index][wt_left] != -1)
            return dp[index][wt_left];

        int pick = 0;
        if (wt[index] <= wt_left)
        {
            pick = helper(index, wt_left - wt[index], val, wt) + val[index];
        }

        int notpick = helper(index - 1, wt_left, val, wt);

        return dp[index][wt_left] = max(pick, notpick);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp, -1, sizeof(dp));
        return helper(N - 1, W, val, wt);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends