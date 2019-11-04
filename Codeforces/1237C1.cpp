#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>

using namespace __gnu_pbds;
using namespace std;

/*--------------------------------- USER'S DEFINE -----------------------------------------*/

#define forn(i, n) for (i = 0; i < n; ++i)
#define for1(i, n) for (i = 1; i <= n; ++i)
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl

/*--------------------------------- USER'S TYPEDEF -----------------------------------------*/

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;

/*---------------------------------POLICY-BASED-DATA STRUCTURES -------------------------------*/

// Set up chash for hash table

ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
ll SEED = ll(new ll);
ll RANDOM = TIME ^ SEED;
ll MOD = (int)1e9 + 7;
ll MUL = (int)1e6 + 3;

// optionn 1 (slower - don't know why)
//struct chash{
//  ll operator()(ll x) const {return std::hash<ll>{}((x^RANDOM)%MOD * MUL);}
//};

// Option 2
struct chash
{
    int operator()(int x) const { return x ^ RANDOM; }
};

// Option 3 (fastest)
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Set up trie
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> u_trie;

// Set up Red-Black Tree
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rb_tree;

/*-----------------------------------USEFUL FUNCS -----------------------------------------------*/

ll binPow(ll a, ll b)
{
    ll x = 1, y = a;
    while (b)
    {
        if (b & 1)
            x = (x * y) % MOD;
        y = (y * y) % MOD;
        b >>= 1;
    }
    return x % MOD;
}

ll inverserEuler(ll n) { return binPow(n, MOD - 2); }

ll C(ll k, ll n)
{
    vll f(n + 1, 1);
    for (ll i = 2; i <= n; i++)
        f[i] = (f[i - 1] * i) % MOD;
    return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n - k])) % MOD) % MOD) % MOD;
}

/* Extend Euclid: ax + by = c;
ll x, y;

void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/

/*--------------------------------- USER'S SOLVE FUNC -------------------------------------------*/

typedef tuple<int, int, int> point;

double dis(point a, point b)
{
    int x1, y1, z1, x2, y2, z2;
    tie(x1, y1, z1) = a;
    tie(x2, y2, z2) = b;
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

void trunghieu()
{
    int n;
    cin >> n;
    vector<point> p;
    map<point, int> index;
    int i, j;
    forn(i, n)
    {
        int x, y, z;
        cin >> x >> y >> z;
        p.emplace_back(x, y, z);
        index[make_tuple(x, y, z)] = i;
    }
    vi visited(n, 0);
    sort(all(p), [](point a, point b) {
        return get<0>(a) < get<0>(b) || get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b) || get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b);
    });
    forn(i, n)
    {
        if (!visited[i])
        {
            int indexDel = -1;
            double minDis = 1e9;
            for (j = i + 1; j < n; j++)
            {
                if (!visited[j])
                {
                    if (dis(p[i], p[j]) < minDis)
                    {
                        minDis = dis(p[i], p[j]);
                        indexDel = j;
                    }
                }
            }
            visited[indexDel] = 1;
            cout << index[p[i]] + 1 << " " << index[p[indexDel]] + 1 << endl;
        }
    }
}

/*--------------------------------- MAIN FUNC ---------------------------------------------------*/

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