#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (i = 0; i < n; ++i)

#define for1(i, n) for (i = 1; i <= n; ++i)

#define pb push_back

#define all(x) (x).begin(), (x).end()

#define fill(x, b) memset((x), b, sizeof((x)))

#define fill2D(x, r, c, b) memset((x), b, sizeof(x[0][0]) * r * c)

typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<vi> vvi;

typedef vector<vll> vvll;

typedef vector<string> vs;

typedef vector<vs> vvs;

const int mod = 1e9 + 7;

ll binPow(ll a, ll b)

{

    ll x = 1, y = a;

    while (b)

    {

        if (b & 1)

            x = (x * y) % mod;

        y = (y * y) % mod;

        b >>= 1;
    }

    return x % mod;
}

ll inverserEuler(int n) { return binPow(n, mod - 2); }

ll C(int k, int n)

{

    vll f(n + 1, 1);

    for (int i = 2; i <= n; i++)

        f[i] = (f[i - 1] * i) % mod;

    return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n - k])) % mod) % mod) % mod;
}

/* Extend Euclid: ax + by = c; */

// ll x, y;

// void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}

// nghiem : x + (b/d)*k, y - (a/d) * k;

/*--------------------------------------------------------------------------------------------------*/

bool checkTaxiNum(string s)

{

    sort(all(s));

    s = s.substr(2);

    return s[0] == s.back();
}

bool checkPizzaNumber(string s)

{

    int cnt = count(all(s), '-');

    int prev = -1;

    for (auto i : s)

    {

        if (i != '-')

        {

            if (prev == -1)

                prev = i - '0';

            else

            {

                if (i - '0' >= prev)

                    return 0;

                else

                    prev = i - '0';
            }
        }
    }

    return 1;
}

int n;

map<string, vi> cnt;

string name[101];

void trunghieu()

{

    cin >> n;

    int i, j;

    forn(i, n)

    {

        int si;

        cin >> si >> name[i];

        string num;

        cnt[name[i]] = vi(3, 0);

        forn(j, si)

        {

            cin >> num;

            if (checkPizzaNumber(num))

                cnt[name[i]][1]++;

            else

            {

                if (checkTaxiNum(num))

                    cnt[name[i]][0]++;

                else
                    cnt[name[i]][2]++;
            }
        }
    }

    int maxTaxiNum = 0, maxPizzaNum = 0, maxGirlNum = 0;

    for (auto i : cnt)

    {

        maxTaxiNum = max(maxTaxiNum, i.second[0]);

        maxPizzaNum = max(maxPizzaNum, i.second[1]);

        maxGirlNum = max(maxGirlNum, i.second[2]);
    }

    vector<vector<string>> ans(3);

    forn(i, n)

    {

        vi tmp = cnt[name[i]];

        if (tmp[0] == maxTaxiNum)

            ans[0].push_back(name[i]);

        if (tmp[1] == maxPizzaNum)

            ans[1].push_back(name[i]);

        if (tmp[2] == maxGirlNum)

            ans[2].push_back(name[i]);
    }

    cout << "If you want to call a taxi, you should call: ";

    forn(i, (int)ans[0].size() - 1)

            cout

        << ans[0][i] << ", ";

    cout << ans[0].back() << ".\n";

    cout << "If you want to order a pizza, you should call: ";

    forn(i, (int)ans[1].size() - 1)

            cout

        << ans[1][i] << ", ";

    cout << ans[1].back() << ".\n";

    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";

    forn(i, (int)ans[2].size() - 1)

            cout

        << ans[2][i] << ", ";

    cout << ans[2].back() << ".\n";
}

int main()

{

    ios::sync_with_stdio(false);

    cin.tie();

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    //freopen("output.txt","w",stdout);

#endif

    trunghieu();

    return 0;
}