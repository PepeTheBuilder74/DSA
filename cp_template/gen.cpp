#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b)
{
    return uniform_int_distribution<int>(a, b)(rng);
}
int main(int argc, char *argv[])
{

    return 0;
}
