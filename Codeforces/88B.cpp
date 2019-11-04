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

double dist(int x1, int y1, int x2, int y2)

{

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int n, m, x;

char key[31][31];

void trunghieu()

{

    cin >> n >> m >> x;

    int i, j, ans = 0, k, i1, j1;

    map<char, vector<pair<int, int>>> pos;

    for1(i, n)

            for1(j, m)

                cin >>
        key[i][j],

        pos[key[i][j]].pb({i, j});

    int q;

    cin >> q;

    string s;

    cin >> s;

    char preChar;

    vector<pair<int, int>> pS = pos['S'];

    map<char, int> can;

    for (auto u : pS)

    {

        for1(i, n)

            for1(j, m)

                if (dist(i, j, u.first, u.second) <= x && key[i][j] != 'S')

                    can[toupper(key[i][j])] = 1;
    }

    forn(i, s.size())

    {

        auto pI = pos[tolower(s[i])];

        if (pI.empty())

        {

            cout << -1;

            return;
        }

        if (isupper(s[i]))

        {

            if (pS.empty())

            {

                cout << -1;

                return;
            }

            else

            {

                if (!can[s[i]])

                {

                    //cout<<s[i]<<" ";

                    ans++;
                }
            }
        }
    }

    cout << ans;
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