
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
    int dp[101][20001];

    bool helper(vector<int> &arr, int sum, int index)
    {
        // base condition
        if (index == 0)
        {
            if (arr[0] == sum)
            {
                return dp[index][sum] = 1;
            }
            return dp[index][sum] = 0;
        }

        // base condition
        if (sum == 0)
        {
            return dp[index][sum] = 1;
        }

        if (dp[index][sum] != -1)
            return dp[index][sum];

        // pick condition or else it will give segmentation fault
        if (arr[index] <= sum)
        {
            if (helper(arr, sum - arr[index], index - 1))
            {
                return true;
            }
        }

        // notpick
        if (helper(arr, sum, index - 1))
        {
            return true;
        }
        return dp[index][sum] = 0;
    }

    bool isSubsetSum(vector<int> &arr, int sum)
    {
        memset(dp, -1, sizeof(dp));
        return helper(arr, sum, arr.size() - 1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}

// } Driver Code Ends