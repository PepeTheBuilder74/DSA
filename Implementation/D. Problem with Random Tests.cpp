// D. Problem with Random Tests
// https://codeforces.com/problemset/problem/1743/D

int main()
{
    // remove for interactive problems
    ios_base::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int zeroidx = -1, oneidx = -1;

        // find the pos of first 1 and remove all zeroes from the 0th index
        oneidx = s.find('1');

        // if no one then our answer is 0
        if (oneidx == -1)
        {
            cout << 0 << "\n";
            continue;
        }

        // 000110001110 is converted to 110001110 now
        string ans = "";
        ans = s.substr(oneidx);

        // find pos of first 0 after 1 because in order to increase OR we need to remove MSB zeroes
        zeroidx = ans.find('0');

        // if there is no zero then our answer is 1111.....
        if (zeroidx == -1)
        {
            cout << ans << endl;
            continue;
        }

        // resultant string
        string res = ans;

        // we can only find the strings which are atleast of length (ans.size-zeroidx ) or else we cannot convert MSB zero to 1 because
        // the length of the string will be less than ans.size-zeroidx
        // so we will start from 0th index till first zero occurence
        for (int i = 0; i <= zeroidx; i++)
        {
            // this is our main string
            string now = ans;

            // we want to have all 1n the string from 0th index thats why we will remove the last bits instead of first
            string temp = ans.substr(0, (int)ans.size() - i);

            // simple OR operation
            for (int j = 0; j + i < (int)ans.size(); j++)
            {
                now[i + j] |= temp[j];
            }
            res = max(res, now);
        }
        cout << res << endl;
    }

    return 0;
}