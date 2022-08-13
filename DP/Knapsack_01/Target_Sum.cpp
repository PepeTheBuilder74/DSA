
#include <bits/stdc++.h>
using namespace std;

/*1. Knapsack 0-1

                                                         Based on pick and not pick
TC->
SC->
ASC->

*/

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{
public:
    int helper(int index, int sum, vector<int> &arr)
    {
        // base condition
        if (index == 0)
        {
            // It doesnt matter if we include 0 in first index or not we will get sum==0 either way thats why we will return 2
            if (arr[index] == 0 && sum == 0)
                return 2;

            return abs(sum) == arr[index];
        }

        int add = helper(index - 1, sum - arr[index], arr);
        int sub = helper(index - 1, sum + arr[index], arr);

        return add + sub;
    }

    int findTargetSumWays(vector<int> &A, int target)
    {
        return helper(A.size() - 1, target, A);
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
        vector<int> arr(N);

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(arr, target);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends