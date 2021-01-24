#include <bits/stdc++.h>

using namespace std;

long long binPow(long long a, long long b, long long mod)
{
    long long x = 1;
    long long y = a;
    while (b)
    {
        if (b & 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        b >>= 1;
    }
    return x % mod;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie();
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        long long m = 0;
        for (int i = 0; i < n; i++)
        {
            m += (s[i] - '0') * binPow(2, n - i - 1, 5);
            m %= 5;
        }
        cout << (m == 0) ? "Yes\n" : "No\n";
    }
    return 0;
}