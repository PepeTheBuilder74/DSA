#include <bits/stdc++.h>
using namespace std;

/*1. Knapsack 0-1

                                                         Based on pick and not pick
TC->
SC->
ASC->

*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dp[1001][1001];

    int helper(int index, int price[], int target)
    {
        if (index == 0)
        {
            return target * price[0];
        }
        int pick = 0;
        if (dp[index][target] != -1)
            return dp[index][target];
        if (index + 1 <= target)
        {
            pick = price[index] + helper(index, price, target - index - 1);
        }
        int notpick = helper(index - 1, price, target);
        return dp[index][target] = max(pick, notpick);
    }

    int cutRod(int price[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return helper(n - 1, price, n);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends