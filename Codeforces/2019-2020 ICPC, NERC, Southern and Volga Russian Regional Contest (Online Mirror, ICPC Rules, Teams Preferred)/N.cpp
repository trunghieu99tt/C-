#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>

using namespace __gnu_pbds;
using namespace std;

/*--------------------------------- RANDOM -----------------------------------------*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// use shuffle(all(x), rng)

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

gp_hash_table<int, vi, custom_hash> adjList;
gp_hash_table<pii, int, chash_key> index;
gp_hash_table<int, int, custom_hash> parent, visited;
set<int> vertex;
void trunghieu()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        visited.clear();
        adjList.clear();
        index.clear();
        vertex.clear();
        int i, j;
        forn(i, n)
        {
            int u, v;
            cin >> u >> v;
            if (!index[{u, v}])
            {
                adjList[u].eb(v);
                adjList[v].eb(u);
                index[{u, v}] = i + 1;
                index[{v, u}] = i + 1;
                vertex.insert(u);
                vertex.insert(v);
            }
        }
        vi lastV;
        for (auto i : vertex)
        {
            if (!visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                parent[i] = i;
                int last = i;
                while (!q.empty())
                {
                    auto u = q.front();
                    q.pop();
                    for (auto v : adjList[u])
                    {
                        if (!visited[v])
                        {
                            q.push(v);
                            visited[v] = 1;
                            parent[v] = u;
                            last = v;
                        }
                    }
                }
                if (last != i)
                    lastV.eb(last);
            }
        }
        if (lastV.size() <= 1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << lastV.size() - 1 << endl;
            int u = lastV[0];
            for1(i, int(lastV.size()) - 1)
            {
                int v = parent[lastV[i]];
                cout << index[{v, lastV[i]}] << " " << lastV[i] << " " << u << endl;
            }
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