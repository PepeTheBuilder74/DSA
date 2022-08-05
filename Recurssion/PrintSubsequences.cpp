#include <bits/stdc++.h>
using namespace std;

/*1. Print Subsequences

TC->
SC->
ASC->

*/

void findSubsequence(string &s, string &up, int index, vector<string> &ans)
{
    if (index == s.size())
    {
        if (up.size() == 0)
        {
            ans.push_back("{ }");
        }
        else
            ans.push_back(up);
        return;
    }
    up.push_back(s[index]);
    findSubsequence(s, up, index + 1, ans);
    up.pop_back();
    findSubsequence(s, up, index + 1, ans);
}

int main()
{
    string s = "abc";
    string up;
    vector<string> ans;
    findSubsequence(s, up, 0, ans);
    for (auto x : ans)
    {
        cout << x << endl;
    }
}