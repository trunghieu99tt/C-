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

vector<ll> build(int n)
{
    set<ll> tmp;
    vector<ll> ans;
    int i;
    for (int k = n; k <= n + 2; k++)
    {
        for (int i = 0; i <= k; i++)
        {
            if (i == k - i)
            {
                string s = string(i, '4') + string(k - i, '7');
                do
                {
                    tmp.insert(stoll(s));
                } while (next_permutation(all(s)));
            }
        }
    }
    for (auto i : tmp)
        ans.pb(i);
    return ans;
}

int n;

void trunghieu()
{
    cin >> n;
    int num = log(n) / log(10) + 1;
    vector<ll> founder = build(num);
    int index = lower_bound(all(founder), n) - founder.begin();
    cout << founder[index] << endl;
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