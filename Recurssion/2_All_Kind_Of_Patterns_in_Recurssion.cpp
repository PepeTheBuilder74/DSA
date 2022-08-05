#include <bits/stdc++.h>
using namespace std;

/*1. Print Subsequences

TC->
SC->
ASC->

*/

void printingSubsequencesWhoseSumIsK(vector<int> &original, vector<int> &ds, int sum, int index, int k)
{
    if (sum == k)
    {
        for (auto &x : ds)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    if (index == original.size())
        return;

    ds.push_back(original[index]);
    sum += original[index];
    printingSubsequencesWhoseSumIsK(original, ds, sum, index + 1, k);
    sum -= original[index];
    ds.pop_back();
    printingSubsequencesWhoseSumIsK(original, ds, sum, index + 1, k);
}

bool printingOnlyOneSubsequenceWhoseSumIsK(vector<int> &original, vector<int> &ds, int sum, int index, int k)
{
    if (sum == k)
    {
        for (auto &x : ds)
        {
            cout << x << " ";
        }
        cout << endl;
        return true;
    }

    if (index == original.size())
        return false;

    ds.push_back(original[index]);
    sum += original[index];
    if (printingOnlyOneSubsequenceWhoseSumIsK(original, ds, sum, index + 1, k))
        return true;
    sum -= original[index];
    ds.pop_back();
    if (printingOnlyOneSubsequenceWhoseSumIsK(original, ds, sum, index + 1, k))
        return true;
    return false;
}

int countSubsequenceWithSumK(vector<int> &original, int sum, int index, int k)
{
    if (sum == k)
    {
        return 1;
    }
    if (sum > k)
    {
        return 0;
    }
    if (index == original.size())
    {
        return 0;
    }

    sum += original[index];
    int l = countSubsequenceWithSumK(original, sum, index + 1, k);
    sum -= original[index];

    int r = countSubsequenceWithSumK(original, sum, index + 1, k);

    return l + r;
}

int main()
{
    vector<int> original = {1, 2, 1, 2, 1};
    vector<int> ds;
    system("cls");
    cout << "Printing All Subsequences " << endl;
    printingSubsequencesWhoseSumIsK(original, ds, 0, 0, 2);

    cout << "Printing Only One Subsequence " << endl;
    printingOnlyOneSubsequenceWhoseSumIsK(original, ds, 0, 0, 2);

    cout << "Counting Total Number of Subsequences " << endl;
    cout << countSubsequenceWithSumK(original, 0, 0, 2) << endl;
}