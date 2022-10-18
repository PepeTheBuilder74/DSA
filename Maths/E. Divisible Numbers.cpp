// E1 - Divisible Numbers

// Easy version
// https://codeforces.com/contest/1744/problem/E1
int main()
{
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {

        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll prod = a * b;

        // ab | xy -> xy= k ab --> y= kab/x means x divides ab in order to get integer there we will ab*__gcd(prod,x) which is equal to ab/x
        // y>c therefore kab/x >c --> k> cx/ab or k= cx/ab +1 -->we have already find ab/x so we will find cx/ab +1
        // brute force to all possible values of x
        for (ll x = a + 1; x <= c; x++)
        {
            ll gcd = __gcd(prod, x);
            ll need = prod / gcd;
            ll k = b / need + 1;
            if (need * k <= d)
            {
                cout << x << " " << need * k << endl;
                goto end;
            }
        }
        cout << "-1 -1" << endl;
    end:;
    }

    return 0;
}

// E-2 Hard version
// https://codeforces.com/contest/1744/problem/E2

int main()
{
    // remove for interactive problems
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {

        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<pair<int, int>> factorsofa, factorsofb;

        for (int i = 1; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                factorsofa.push_back({i, a / i});
                factorsofa.push_back({a / i, i});
            }
        }
        for (int i = 1; i * i <= b; i++)
        {
            if (b % i == 0)
            {
                factorsofb.push_back({i, b / i});
                factorsofb.push_back({b / i, i});
            }
        }
        // k is constant
        // xy=kab--> xy= k1a1b1 k2a2b2 -->x=k1a1b1 ,y=k2b2a2 or x=k1a1b2,y=k2b1a2 or x=k1a2b1,y=k2b2a1 or x=k1a2b2,y=k2b1a1

        // it is proven that divisors of number are not more than (number)^1/3 there fore total complexity is O(10^6)
        for (auto x : factorsofa)
        {
            for (auto y : factorsofb)
            {
                ll a1 = x.first, a2 = x.second, b1 = y.first, b2 = y.second;
                ll prod1 = a1 * b1, prod2 = a2 * b2;
                ll k1 = a / prod1 + 1, k2 = b / prod2 + 1;
                if (k1 * prod1 <= c && k2 * prod2 <= d)
                {
                    cout << k1 * prod1 << " " << k2 * prod2 << endl;
                    goto end;
                }
            }
        }

        cout << "-1 -1" << endl;
    end:;
    }

    return 0;
}