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

// using pair as key

struct chash_key

{

    int operator()(pii x) const { return x.first * 31 + x.second; }
};

// Set up trie

typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> u_trie;

// Set up Red-Black Tree

template <typename T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int maxn = 2e5 + 5;

vi a(maxn);

vi visited(maxn);

vi group(maxn);

vi groupSize(maxn);

void trunghieu()

{

    int q;

    cin >> q;

    while (q--)

    {

        int n;

        cin >> n;

        a.resize(n);

        visited.assign(n + 1, 0);

        group.resize(n + 1);

        int idGroup = 1;

        for (auto &i : a)

            cin >> i;

        for (auto i : a)

        {

            if (!visited[i - 1])

            {

                int x = i - 1;

                group[x] = idGroup;

                int cnt = 0;

                while (1)

                {

                    x = a[x] - 1;

                    if (visited[x])

                        break;

                    cnt++;

                    group[x] = idGroup;

                    visited[x] = 1;
                }

                groupSize[idGroup] = cnt;

                idGroup++;
            }
        }

        int i, j;

        forn(i, n)

                cout

            << groupSize[group[i]] << " ";

        cout << endl;
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