// Number of swaps to sort when only adjacent swapping allowed

/*
There is an interesting solution to this problem. It can be solved using the fact that a number of swaps needed is equal to number of inversions.
So we basically need to count inversions in array.

The fact can be established using below observations:
1.A sorted array has no inversions.
2.An adjacent swap can reduce one inversion. Doing x adjacent swaps can reduce x inversions in an array.

 */

/*Question : D - "redocta".swap(i,i+1) atcoder
Problem Statement :

You are given a string
S that is a permutation of atcoder.
On this string S, you will perform the following operation 0 or more times:
Choose two adjacent characters of S and swap them.
Find the minimum number of operations required to make S equal atcoder.

*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
int CountSteps(string s1, string s2, int size);
void solve()

{
    string s2;
    cin >> s2;
    string s1 = "atcoder";
    int A[s1.size()];
    int cnt = 0;

    // first we are setting up our array for inversions
    rep(i, s1.size())
    {
        rep(j, s1.size())
        {
            if (s1[i] == s2[j])
            {
                A[i] = j;
                break;
            }
        }
    }

    // now we are counting inversions
    for (int i = 0; i < 7; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            if (A[i] > A[j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    // Time complexity is O(n^2) for this code but we can solve it in O(nlogn) using merge sort
    cout << CountSteps(s1, s2, s1.size());
    // Other method is to use 2 pointer but it is O(n^2)
}

// string to be made is s2  and s1 is the string which is given as input
int CountSteps(string s1, string s2, int size)
{
    int j = 0;
    int result = 0;
    // Iterate over the first string and convert
    // every element equal to the second string
    for (int i = 0; i < size; i++)
    {
        j = i;

        // Find index element of first string which
        // is equal to the ith element of second string
        while (s1[j] != s2[i])
        {
            j++;
        }

        // Swap adjacent elements in first string so
        // that element at ith position becomes equal
        while (i < j)
        {
            // Swap elements using temporary variable
            swap(s1[j], s1[j - 1]);
            j--;
            result++;
        }
    }
    return result;
}

int main()
{

    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
