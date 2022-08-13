
#include <bits/stdc++.h>
using namespace std;

/*1. Knapsack 0-1

                                                         Based on pick and not pick
TC->
SC->
ASC->

*/
// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // memo
    int dp[101][20005];

    bool helper(int index, int target, int arr[])
    {
        // succesful base condition
        if (target == 0)
            return true;
        // base condtition
        if (index == 0)
        {
            if (arr[0] == target)
                return dp[index][target] = true;
            return dp[index][target] = false;
        }
        // unsucessful base
        if (target < 0)
            return false;

        if (dp[index][target] != -1)
            return dp[index][target];

        // pick
        if (arr[index] <= target)
        {
            if (helper(index - 1, target - arr[index], arr))
            {
                return true;
            }
        }

        // not pick
        if (helper(index - 1, target, arr))
        {
            return true;
        }

        return dp[index][target] = false;
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }

        // if sum is odd then we cant divide into two equal halves
        if (sum & 1)
            return 0;

        memset(dp, -1, sizeof(dp));

        return helper(N - 1, sum / 2, arr);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends