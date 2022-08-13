
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
    int mod = 1000000007;
    int solve(int ind, int sum, int arr[], vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (sum == 0 && arr[0] == 0)
                return 2;
            if (sum == 0 || arr[0] == sum)
                return 1;
            return 0;
        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int not_take = (solve(ind - 1, sum, arr, dp)) % mod;

        int take = 0;

        if (arr[ind] <= sum)
            take = solve(ind - 1, sum - arr[ind], arr, dp) % mod;

        return (dp[ind][sum] = take + not_take) % mod;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, sum, arr, dp);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends