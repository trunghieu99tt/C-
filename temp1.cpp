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

#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
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

//Extend Euclid: ax + by = c;
ll x, y;

void extendEuclid(ll a, ll b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    extendEuclid(b, a % b);
    ll x1 = y, y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
// nghiem : x + (b/d)*k, y - (a/d) * k;

/*--------------------------------- USER'S SOLVE FUNC -------------------------------------------*/

void solve()
{
    int n;
    cin >> n;
    int s = 2 * n + 1;
    int i, j;

    vvi cost(s, vi(s));

    forn(i, s)
            forn(j, s)
                cin >>
        cost[i][j];
    vi point(2 * n + 1);
    forn(i, s)
        point[i] = i;
    point.eb(0);
    int ans = INT_MAX, cnt = 0;
    while (clock() <= 0.98 * CLOCKS_PER_SEC)
    {
        shuffle(begin(point) + 1, end(point), rng);
        int currPassenger = -1, isOk = 1, prev = 0, currAns = 0, passengerCounter = 0, isEnd = false;
        int prevPoint = 0;
        for1(i, int(point.size()) - 1)
        {
            currAns += cost[prevPoint][point[i]];
            if (point[i] == 0)
                break;

            // Nếu không có hành khách nào => cho lên
            if (currPassenger == -1)
            {
                currPassenger = point[i];
                passengerCounter++;
            }
            else
            {
                // Nếu đã có khách mà qua 1 điểm chờ nào đó thì chắc chắn chu
                // trình này sai.
                if (point[i] <= n)
                {
                    isOk = false;
                    break;
                }
                else
                {
                    // Nếu là điểm chờ của khách thì cho khách xuống.
                    if (point[i] == currPassenger + n)
                        currPassenger = -1;
                }
            }
            prevPoint = point[i];
            if (currAns > ans)
            {
                isOk = false;
            }
                }

        // Đưa được tất cả các khách đến địa điểm của mình cũng như không còn khách nào trên xe khi trở về điểm xuất phát.
        cnt++;
        if (isOk && passengerCounter == n && currPassenger == -1)
        {
            ans = min(ans, currAns);
        }
        next_permutation(begin(point) + 1, end(point));
    }
    // whatIs(cnt);
    cout << ans;
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
    solve();
    return 0;
}