#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

#define forn(i, n) for (i = 0; i < n; ++i)

#define for1(i, n) for (i = 1; i <= n; ++i)

#define eb emplace_back

#define all(x) (x).begin(), (x).end()

#define fill(x, b) memset((x), b, sizeof((x)))

#define fill2D(x, r, c, b) memset((x), b, sizeof(x[0][0]) * r * c)

#define whatIs(a) cout << #a << " is : " << a << endl

typedef long long ll;

typedef vector<ll> vi;

typedef vector<ll> vll;

typedef vector<vi> vvi;

typedef vector<vll> vvll;

typedef vector<string> vs;

typedef vector<vs> vvs;

const ll mod = 1e9 + 7;

clock_t t1, t2;

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

ll inverserEuler(ll n) { return binPow(n, mod - 2); }

ll C(ll k, ll n)
{
    vll f(n + 1, 1);
    for (ll i = 2; i <= n; i++)
        f[i] = (f[i - 1] * i) % mod;
    return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n - k])) % mod) % mod) % mod;
}

/* Extend Euclid: ax + by = c;

ll x, y;



void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}

// nghiem : x + (b/d)*k, y - (a/d) * k;

*/

/*--------------------------------------------------------------------------------------------------*/

const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

struct chash
{

    ll operator()(ll x) const { return x ^ RANDOM; }
};

const int maxn = 2e5 + 5;

vector<pair<int, int>> t(maxn);

int n;

void trunghieu()

{

    cin >> n;

    int i, j;

    forn(i, n)

            cin >>
        t[i].first >> t[i].second;

    sort(begin(t), begin(t) + n, [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first || a.first == b.first && a.second < b.second;
    });

    stack<pair<int, int>> stA, stB;

    forn(i, n)
    {

        if (stA.empty())
        {

            stA.push(t[i]);
        }
        else if (stB.empty())
        {

            stB.push(t[i]);
        }
        else
        {

            auto u = stA.top();

            auto v = stB.top();

            if (u.second < t[i].first)
            {

                stA.pop();

                stA.push(t[i]);
            }
            else if (v.second < t[i].first)
            {

                stB.pop();

                stB.push(t[i]);
            }
            else
            {

                cout << "NO\n";

                return;
            }
        }
    }

    cout << "YES\n";
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
