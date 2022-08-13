#include <bits/stdc++.h>
using namespace std;

/*1. Knapsack 0-1

                                                         Based on pick and not pick
TC->
SC->
ASC->

*/
/*
These are few of the dp patterns along with problems of that particular pattern.

Kadane's Algo:

    1.Maximum difference of 0's and 1's in a binary string
    2.Maximum Sum Circular array
    3.Smallest sum contiguous subarray
    4.Largest sum increasing contiguous subarray
    5.Maximum Product Subarray
    6.Largest sum contiguous subarray with only non-negative elements.
    7.Largest sum contiguous subarray with unique elements.
    8.Maximum Alternating Sum Subarray
    9.Maximum Sum Rectangle In A 2D Matrix

LIS:

    1.Maximum Sum Increasing Subsequence
    2.Print LIS
    3.Best Team with No Conflicts (LC 1626)
    4.No of LIS
    5.Increasing Triplet Subsequence
    6.LIS having sum almost K
    7.Minimum Number of Removals to Make Mountain Array

MCM:

    1.Priting MCM
    2.Burst Ballons
    3.Evaluate Expression to True/ Boolean Paranthesization
    4.Minimum / Maximum Value of an Expression
    5.Pallindrome Partitioning
    6.Scramble String
    7.Egg Dropping Problem

LCS:

    1.Longest Common Substring
    2.Print LCS
    3.Shortest Common Supersequence
    4.Print SCS
    5.Minimum number of insertions and deletions to from String a from String b
    6.Largest Repeating Subsequence
    7.Length of largest subsequence of which is a substring in b
    8.Subsequence Pattern Matching
    9.Count number of times a appear as subsequence in b
    10.Largest Pallindromic Subsequence
    11.Longest Pallindromic Substring
    12.Count of Pallindromic Substring
    13.Minimum deletions to make a string Pallindrome
    14.Minimum insertions to make a string Pallindrome
    15.Minimum deletions to make a->b

Unbounded Knapsack:

    1.Rod cutting problem
    2.Coin Change 1
    3.Coin Change 2
    4.Maximum Ribbon Cut
    5.Number Partitioning

0/1 Knapsack:

    1.Subset Sum                        -->done
    2.Equal Sum Partition               -->done
    3.Count of subset with given sum
    4.Minimum subset sum difference
    5.Target Sum
    6.No of susbet with given differences
    7.Count of subsets with given difference
    8.Last Stone Weight 2(LC 1049)

Fibonacci Numbers:

    1.Fibonacci numbers
    2.Staircase
    3.Number factors
    4.Minimum jumps to reach the end
    5.Minimum jumps with fee
    6.House thief


              https://leetcode.com/discuss/general-discussion/592146/Dynamic-Programming-Summary
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // dp array
    int dp[1005][1001];

    int helper(int index, int wt_left, int wt[], int val[])
    {
        // base condition
        if (index == 0)
        {
            if (wt[0] <= wt_left)
            {
                return val[0];
            }
            return 0;
        }

        if (dp[index][wt_left] != -1)
            return dp[index][wt_left];

        // not pick
        int notpick = 0 + helper(index - 1, wt_left, wt, val);
        int pick = INT_MIN;

        // pick
        if (wt[index] <= wt_left)
        {
            pick = val[index] + helper(index - 1, wt_left - wt[index], wt, val);
        }

        return dp[index][wt_left] = max(pick, notpick);
    }

    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return helper(n - 1, W, wt, val);
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends