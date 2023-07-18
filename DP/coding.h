#include <bits/stdc++.h>
#define dbg(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)

void __print(int32_t x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(int64_t x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T>
void __print(complex<T> x)
{
    cerr << '{';
    __print(x.real());
    cerr << ',';
    __print(x.imag());
    cerr << '}';
}

template <typename T>
void __print(const T &x);

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto it = x.begin(); it != x.end(); it++)
        cerr << (f++ ? "," : ""), __print(*it);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}