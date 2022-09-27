// B.AND Sequences

// main observation is that and of prefix and suffix is same as and of whole array-->lets say and of whole array is x
// so we can use this observation to solve this problem
// first we will count the number of elements equal to x in the array
// because x is the lowest element in the array and & of elements cant get lower than x
// so we will count the number of elements equal to x
// if x < 2 then we will print 0 because we have to make suffix and prefix equal to x so we have to fix x to first and last index
// if x >=2 then in how many ways can we arrange 2 elements from n elements to fix end positions? its  nP2  or n*n-1
// we can arrange rest of the elements as it is in (n-2)! ways

void solve()
{

    int n;
    cin >> n;
    int arr[n];
    int totalAnd;
    rep(i, n)
    {
        cin >> arr[i];
        if (!i)
            totalAnd = arr[i];
        else
            totalAnd &= arr[i];
    }
    ll cntAnd = 0;
    rep(i, n)
    {
        if (arr[i] == totalAnd)
        {
            cntAnd++;
        }
    }
    if (cntAnd < 2)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        ll ans = (cntAnd * (cntAnd - 1) % MOD) % MOD;
        vector<ll> fact(n + 2, 1);
        fact[0] = 1;
        for (ll i = 1; i <= n - 2; i++)
        {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        ans = (ans * fact[n - 2]) % MOD;
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
