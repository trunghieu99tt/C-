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

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int K;
        cin >> K;
        vector<pair<double, double>> aa(n);
        for (auto &i : aa)
            cin >> i.first >> i.second;
        bool f = 0;
        forn(i, n)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    double x1 = aa[i].first, y1 = aa[i].second;
                    double x2 = aa[j].first, y2 = aa[j].second;
                    double x3 = aa[k].first, y3 = aa[k].second;
                    double a = x1 * x1 - x2 * x2 + y1 * y1 - y2 * y2;
                    double b = x1 - x2;
                    double c = y1 - y2;
                    double a1 = x1 * x1 - x3 * x3 + y1 * y1 - y3 * y3;
                    double b1 = x1 - x3;
                    double c1 = y1 - y3;

                    if (c1 * b - c * b1 != 0 && b != 0)
                    {
                        double y = -(a * b1 - a1 * b) * 1.0 / (2 * (c1 * b - c * b1));
                        double x = (a - 2 * c * y) * 1.0 / (2 * b);
                        double R = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
                        double cnt = 0;
                        for (int l = 0; l < n; l++)
                        {
                            if (l != i && l != j && l != k)
                            {
                                double xx = aa[l].first;
                                double yy = aa[l].second;
                                double dis = (xx - x) * (xx - x) + (yy - y) * (yy - y);
                                if (dis < R)
                                    cnt++;
                                if (cnt > K)
                                    break;
                            }
                        }
                        if (cnt == K)
                        {
                            cout << "YES\n";
                            f = 1;
                            break;
                        }
                    }
                }
                if (f)
                    break;
            }
            if (f)
                break;
        }
        if (!f)
            cout << "NO\n";
    }
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