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
    int T;
    cin >> T;

    while (T--)
    {
        int A[1001][1001];
        int N, M, K;
        cin >> N >> M >> K;
        string s;

        for (int i = 0; i <= N; ++i)
        {
            if (i != 0)
            {
                cin >> s;
                int m = s.size();
                for (int j = 0; j <= m; ++j)
                {
                    if (j == 0)
                    {
                        A[i][j] = 0;
                    }
                    else
                    {
                        A[i][j] = s[j - 1] - '0';
                    }
                }
            }
            else
            {
                for (int j = 0; j <= M; ++j)
                {
                    A[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                A[i][j] = A[i][j] + A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        int cnt = 0;
        for (int k = 1; k <= N; ++k)
        {
            for (int p = 1; p <= M; ++p)
            {
                if (A[k][p] == K)
                {

                    cnt += 1;
                }
                else if (A[k][p] < K)
                {
                    continue;
                }
                if (A[k][p] >= K)
                {
                    bool f = false;
                    bool oke = false;
                    if (k == 1)
                    {
                        for (int j = 1; j < p; ++j)
                        {
                            if (A[k][p] - A[k][j] == K)
                            {

                                cnt += 1;
                            }
                            else if (A[k][p] - A[k][j] < K)
                            {
                                break;
                            }
                        }
                    }
                    else if (p == 1)
                    {
                        for (int i = 1; i < k; ++i)
                        {

                            if (A[k][p] - A[i][p] == K)
                            {

                                cnt += 1;
                            }
                            else if (A[k][p] - A[i][p] < K)
                            {
                                break;
                            }
                        }
                    }

                    else
                    {
                        for (int i = 2; i < k; ++i)
                        {

                            if (A[k][p] - A[i][p] == K)
                            {

                                cnt += 1;
                            }
                            else if (A[k][p] - A[i][p] < K)
                            {
                                f = true;
                            }
                            for (int j = 2; j < p; ++j)
                            {
                                if (A[k][p] - A[k][j] == K)
                                {

                                    cnt += 1;
                                }
                                else if (A[k][p] - A[k][j] < K)
                                {
                                    break;
                                }
                                if (!f)
                                {
                                    if (A[k][p] - A[i][p] - A[k][j] + A[i][j] == K)
                                    {

                                        cnt++;
                                    }
                                }
                            }
                            if (f == true)
                            {

                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
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
    solve();
    return 0;
}