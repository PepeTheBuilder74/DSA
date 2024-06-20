#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b)
{
    return uniform_int_distribution<int>(a, b)(rng);
}
int main(int argc, char *argv[])
{
    int t = 1;
    cout << t << endl;
    for (int i = 0; i < t; i++)
    {
        int n = rand(5, 10);
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << rand(2, 10) << ' ';
        }
        cout << endl;
    }
    return 0;
}