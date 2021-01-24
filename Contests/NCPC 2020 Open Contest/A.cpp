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
typedef pair<int, int> pii;

/*---------------------------------POLICY-BASED-DATA STRUCTURES -------------------------------*/

// Set up chash for hash table

ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
ll SEED = ll(new ll);
ll RANDOM = TIME ^ SEED;
ll MOD = (int)1e9 + 7;
ll MUL = (int)1e6 + 3;

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

/*--------------------------------- FUNC -------------------------------------------*/

bool check(vector<pair<ll, int>> a)
{
    sort(all(a));
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i].second != a[i + 1].second - 1)
            return 1;
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    forn(i, n)
    {
        string s = to_string(a[i].first);
        forn(j, s.size())
        {
            char start;
            if (j == 0 && s.size() > 1)
                start = '1';
            else
                start = '0';
            for (char c = start; c <= '9'; c++)
            {
                string t = s;
                t[j] = c;
                auto temp = a;
                temp[i].first = stoll(t);
                if (check(temp))
                {
                    for (auto k : temp)
                        cout << k.first << " ";
                    return;
                }
            }
        }
    }
    cout << "impossible";
}

/*--------------------------------- MAIN FUNC ---------------------------------------------------*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
#endif
    solve();
    return 0;
}