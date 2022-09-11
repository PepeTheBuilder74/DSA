
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
void TOH(int n, int Sour, int Aux, int Des)
{
    if (n == 1)
    {
        cout << Sour << " " << Des << endl;
        return;
    }

    TOH(n - 1, Sour, Des, Aux);
    cout << Sour << " " << Des << endl;
    TOH(n - 1, Aux, Sour, Des);
}
int main()
{
    int n;
    cin >> n;
    int x = n;
    cout << (1 << x) - 1 << endl;
    TOH(n, 1, 2, 3);
    return 0;
}