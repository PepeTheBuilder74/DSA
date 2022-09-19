// E - Last Rook

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define ar array
const int MxN = 2e5;
ar<int, 2> v[MxN];

int main()
{
    int n;
    cin >> n;
    int low = 1, high = n;
    int r = -1, c = -1;

    // for finding column  keep row fixed
    // if high - mid+ 1 == x then we have to move to search to left half because there are already x number
    // of rooks in right half and we cannot place more than x  in that half 

    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << "? " << 1 << " " << n << " " << mid << " " << high << endl;
        int x;
        cin >> x;
        if (x == 0)
        {
            c = mid;
            break;
        }

        if (x == high - mid + 1)
        {
            high = mid - 1;
        }
        else
        {
            c = mid;
            low = mid + 1;
        }
    }

    // for finding row  keep column fixed
    // if high - mid+ 1 == x then we have to move to search in left half because there are already x number
    // of rooks in right half
    low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << "? " << mid << " " << high << " " << 1 << " " << n << endl;
        int x;
        cin >> x;
        if (x == 0)
        {
            r = mid;
            break;
        }

        if (x == high - mid + 1)
        {
            high = mid - 1;
        }
        else
        {
            r = mid;
            low = mid + 1;
        }
    }

    cout << "! " << r << " " << c << endl;
}
