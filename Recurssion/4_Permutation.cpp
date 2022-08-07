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
    void helper(int index, string s, set<string> &ans)
    {
        if (index == s.size())
        {
            ans.insert(s);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            swap(s[index], s[i]);
            helper(index + 1, s, ans);
            swap(s[index], s[i]);
        }
    }

    vector<string> find_permutation(string s)
    {
        set<string> ans;
        vector<string> final;
        helper(0, s, ans);
        for (auto &x : ans)
        {
            final.push_back(x);
        }
        return final;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
