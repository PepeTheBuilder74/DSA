// D. Divisibility by 2^n
// https://codeforces.com/contest/1744/problem/D
ll count(ll n)
{
    return __builtin_ctz(n);
}

int main()
{
    // remove for interactive problems
    ios_base::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {

        int n;
        cin >> n;
        vector<ll> a(n);
        ll cnt = 0;
        ll ans = n;
        rep(i, n)
        {
            cin >> a[i];
            cnt += count(a[i]);
        }
        if (cnt >= n)
        {
            cout << 0 << endl;
            continue;
        }
        ans -= cnt;
        vector<ll> b;
        for (ll i = 1; i <= n; i++)
        {
            b.push_back(count(i));
        }
        sort(all(b));
        reverse(all(b));
        ll sum = 0;
        for (auto &x : b)
        {
            ans -= x;
            sum++;
            if (ans <= 0)
                break;
        }
        cout << (ans > 0 ? -1 : sum) << endl;
    }

    return 0;
}