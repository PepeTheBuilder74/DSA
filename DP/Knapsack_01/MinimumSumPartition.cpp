#include <bits/stdc++.h>
using namespace std;

/*1. Knapsack 0-1

                                                         Based on pick and not pick
TC->
SC->
ASC->

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int dp[101][20001];
    int total = 0;
    int helper(int arr[], int index, int sum1)
    {
        if (index == 0)
        {
            return abs(2 * sum1 - total);
        }
        if (dp[index][sum1] != -1)
            return dp[index][sum1];
        int pick = helper(arr, index - 1, sum1 - arr[index]);
        int notpick = helper(arr, index - 1, sum1);
        return dp[index][sum1] = min(pick, notpick);
    }

    int minDifference(int arr[], int n)
    {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        return helper(arr, n - 1, total);
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
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends