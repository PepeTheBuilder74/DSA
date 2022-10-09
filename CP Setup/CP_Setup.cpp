{
    "power" : {
        "prefix" : "poww",
        "body" : [
            "ll Pow(ll a, ll b, ll m = MOD)",
            "{",
            "    int res = 1;",
            "    while (b)",
            "    {",
            "        if (b & 1)",
            "            res = (res % m * a % m) % m;",
            "        a = (a % m * a % m) % m;",
            "        b >>= 1;",
            "    }",
            "    return res;",
            "}"
        ],
        "description" : ""
    },
              "maths" : {
                  "prefix" : "combinatrics",
                  "body" : [
                      "class Factorial",
                      "{",
                      "public:",
                      "    vector<ll> factorial;",
                      "    vector<ll> inv_factorial;",
                      "    ll binexp(ll a, ll b, int m)",
                      "    {",
                      "        int res = 1;",
                      "        while (b)",
                      "        {",
                      "            if (b & 1)",
                      "                res = (res % m * a % m) % m;",
                      "            a = (a % m * a % m) % m;",
                      "            b >>= 1;",
                      "        }",
                      "        return res;",
                      "    }",
                      "    ll modulo;",
                      "    Factorial(int n, ll MODULO)",
                      "    {",
                      "        modulo = MODULO;",
                      "        factorial.resize(n + 1);",
                      "        inv_factorial.resize(n + 1);",
                      "        factorial[0] = 1;",
                      "        inv_factorial[0] = 1;",
                      "        for (int i = 1; i <= n; i++)",
                      "        {",
                      "            factorial[i] = (factorial[i - 1] % modulo * i % modulo) % modulo;",
                      "            inv_factorial[i] = binexp(factorial[i], modulo - 2, modulo);",
                      "        }",
                      "    }",
                      "    ll factorialof(ll n)",
                      "    {",
                      "        return factorial[n];",
                      "    }",
                      "    ll inversefactorialof(ll n)",
                      "    {",
                      "        return inv_factorial[n];",
                      "    }",
                      "    ll ncr(ll n, ll r)",
                      "    {",
                      "        if (r > n)",
                      "            return 0;",
                      "        return (factorial[n] % modulo * inv_factorial[r] % modulo * inv_factorial[n - r] % modulo) % modulo;",
                      "    }",
                      "    ll npr(ll n, ll r)",
                      "    {",
                      "        if (r > n)",
                      "            return 0;",
                      "        return (factorial[n] % modulo * inv_factorial[n - r] % modulo) % modulo;",
                      "    }",
                      "};"
                  ],
                  "description" : ""

              },
                        "extended" : {
                            "prefix" : "extended euclid",
                            "body" : [
                                "struct triplet",
                                "{",
                                "    int x;",
                                "    int y;",
                                "    int gcd;",
                                "};",
                                "",
                                "triplet extendedEuclid(int a, int b)",
                                "{",
                                "    // Base case",
                                "    if (b == 0)",
                                "    {",
                                "        triplet myAns;",
                                "        myAns.gcd = a;",
                                "        myAns.x = 1;",
                                "        myAns.y = 0;",
                                "        return myAns;",
                                "    }",
                                "",
                                "    // Recursive case",
                                "    triplet smallAns = extendedEuclid(b, a % b);",
                                "    triplet myAns;",
                                "    myAns.gcd = smallAns.gcd;",
                                "    myAns.x = smallAns.y;",
                                "    myAns.y = smallAns.x - (a / b) * smallAns.y;",
                                "    return myAns;",
                                "}"
                            ],
                            "description" : ""
                        },
                                     "sieve" : {
                                         "prefix" : "sieve",
                                         "body" : [
                                             "void sieve(int n)",
                                             "{",
                                             "    bool prime[n + 1];",
                                             "    memset(prime, true, sizeof(prime));",
                                             "    for (int p = 2; p * p <= n; p++)",
                                             "    {",
                                             "        if (prime[p] == true)",
                                             "        {",
                                             "            for (int i = p * p; i <= n; i += p)",
                                             "                prime[i] = false;",
                                             "        }",
                                             "    }",
                                             "    for (int p = 2; p <= n; p++)",
                                             "        if (prime[p])",
                                             "            cout << p << \" \";",
                                             "}"
                                         ],
                                         "description" : ""
                                     },

                                               "getfactors" : {
                                                   "prefix" : "getfactors",
                                                   "body" : [
                                                       "class getFactors",
                                                       "{",
                                                       "public:",
                                                       "    int n;",
                                                       "    vector<ll> minPrime;",
                                                       "    getFactors(int n)",
                                                       "    {",
                                                       "        minPrime.resize(n + 1);",
                                                       "        for (int i = 2; i * i <= n; ++i)",
                                                       "        {",
                                                       "            if (minPrime[i] == 0)",
                                                       "            { // If i is prime",
                                                       "                for (int j = i * i; j <= n; j += i)",
                                                       "                {",
                                                       "                    if (minPrime[j] == 0)",
                                                       "                    {",
                                                       "                        minPrime[j] = i;",
                                                       "                    }",
                                                       "                }",
                                                       "            }",
                                                       "        }",
                                                       "        for (int i = 2; i <= n; ++i)",
                                                       "        {",
                                                       "            if (minPrime[i] == 0)",
                                                       "            {",
                                                       "                minPrime[i] = i;",
                                                       "            }",
                                                       "        }",
                                                       "    }",
                                                       "    // in logn time",
                                                       "    vector<int> factorize(int n)",
                                                       "    {",
                                                       "        vector<int> res;",
                                                       "        while (n != 1)",
                                                       "        {",
                                                       "            res.push_back(minPrime[n]);",
                                                       "            n /= minPrime[n];",
                                                       "        }",
                                                       "        return res;",
                                                       "    }",
                                                       "};"
                                                   ],
                                                   "description" : ""
                                               },
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1e18
#ifndef ONLINE_JUDGE
#include "coding.h"
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long double lld;
typedef unsigned long long int ull;
#define endl "\n"
#define ll long long int
const int MOD = 1e9 + 7;
//-----------------------------------------------------------------------------------------------------------------------------//

void amogus()
{
    
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
        amogus();
    }
}