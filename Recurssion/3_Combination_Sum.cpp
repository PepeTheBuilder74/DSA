#include <bits/stdc++.h>
using namespace std;

/*3.Combination Sum

TC->
SC->
ASC->

*/

class Solution
{
public:
    void helper(vector<vector<int>> &ans, vector<int> &ds, int index, int target, vector<int> candidates)
    {

        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if (target < 0 || index == candidates.size())
            return;

        // pick
        if (candidates[index] <= target)
        {

            ds.push_back(candidates[index]);
            helper(ans, ds, index, target - candidates[index], candidates);
            ds.pop_back();
        }

        // notpick
        helper(ans, ds, index + 1, target, candidates);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(ans, ds, 0, target, candidates);
        return ans;
    }
};
class Solution
{
public:
    void helper(vector<vector<int>> &ans, vector<int> &ds, int index, int target, vector<int> &candidates)
    {

        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if (target <= 0)
            return;

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                return;
            if (i > index && candidates[i] == candidates[i - 1] && i)
                continue;

            ds.push_back(candidates[i]);
            helper(ans, ds, i + 1, target - candidates[i], candidates);

            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &num, int target)
    {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        vector<int> local;
        helper(res, local, 0, target, num);

        return res;
    }
};