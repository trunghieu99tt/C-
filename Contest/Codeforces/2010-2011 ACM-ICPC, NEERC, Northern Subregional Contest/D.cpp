#include <bits/stdc++.h>

using namespace std;

/*--------------------------------- USER'S DEFINE -----------------------------------------*/

#define forn(i, n) for (i = 0; i < n; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi f;

void trunghieu()
{
    int r, c, i, j, n, ans = 0, k;
    cin >> r >> c;
    f = vvi(r, vi(c, 1));
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        forn(j, c)
            f[x][j] = 0;
        forn(i, r)
            f[i][y] = 0;
    }
    forn(i, r)
    {
        forn(j, c)
        {
            if (f[i][j] == 1)
            {
                if (i == 0)
                    f[i][j] = 1;
                else
                    f[i][j] = f[i - 1][j] + 1;
            }
        }
    }
    vi l, ri;
    stack<int> d;
    forn(i, r)
    {
        l.resize(c);
        ri.resize(c);
        while (!d.empty())
            d.pop();
        forn(k, c)
        {
            while (!d.empty() && f[i][d.top()] >= f[i][k])
                d.pop();
            if (d.empty())
                l[k] = -1;
            else
                l[k] = d.top();
            d.push(k);
        }
        while (!d.empty())
            d.pop();
        for (k = c - 1; k >= 0; k--)
        {
            while (!d.empty() && f[i][d.top()] >= f[i][k])
                d.pop();
            if (d.empty())
                ri[k] = n;
            else
                ri[k] = d.top();
            d.push(k);
        }
        forn(k, c)
            ans = max(ans, f[i][k] * (ri[k] - l[k] - 1));
    }
    cout << ans << endl;
}

/*--------------------------------- MAIN FUNC ---------------------------------------------------*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    // freopen("defense.in", "r", stdin);
    // freopen("defense.out", "w", stdout);
    trunghieu();
    return 0;
}