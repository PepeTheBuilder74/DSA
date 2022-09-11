#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{

    vector<vector<int>> ans;
    int n = nums.size();
    int susbset_ct = 1 << n;
    for (int mask = 0; mask < susbset_ct; mask++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
            {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

// time complexity: O(2^n * n)
// space complexity: O(2^n * n)
// auxillary space: O(n)
