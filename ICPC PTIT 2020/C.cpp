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

vector<int> a1;
vector<int> a2;
vector<int> a3;

vector<int> num(string s)
{
    set<int> xx;
    vector<int> ans;
    if (s.find('?') == string::npos)
        return {stoi(s)};
    if (s[0] == '?' && s[1] == '?')
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                string temp = to_string(i) + to_string(j);
                xx.insert(stoi(temp));
            }
        }
    }
    else if (s[0] == '?')
    {
        for (int i = 1; i <= 9; i++)
        {
            string temp = to_string(i) + s[1];
            xx.insert(stoi(temp));
        }
    }
    else if (s[1] == '?')
    {
        for (int i = 0; i <= 9; i++)
        {
            string temp = s[0] + to_string(i);
            xx.insert(stoi(temp));
        }
    }
    for (auto i : xx)
        ans.eb(i);
    return ans;
}

bool check(int a, int b, int c, int o)
{
    if (a < 10 || b < 10 || c < 10)
        return 0;
    if (o == 1)
        return a + b == c;
    if (o == 2)
        return a - b == c;
    if (o == 3)
        return a * b == c;
    if (o == 4)
        return c * b == a;
}

string format(int a, int b, int c, int o)
{
    if (o == 1)
        return to_string(a) + " + " + to_string(b) + " = " + to_string(c);
    if (o == 2)
        return to_string(a) + " - " + to_string(b) + " = " + to_string(c);
    if (o == 3)
        return to_string(a) + " * " + to_string(b) + " = " + to_string(c);
    if (o == 4)
        return to_string(a) + " / " + to_string(b) + " = " + to_string(c);
}

string format1(int a, int b, int c, int o)
{
    if (o == 1)
        return to_string(a) + " = " + to_string(b) + " + " + to_string(c);
    if (o == 2)
        return to_string(a) + " = " + to_string(b) + " - " + to_string(c);
    if (o == 3)
        return to_string(a) + " = " + to_string(b) + " * " + to_string(c);
    if (o == 4)
        return to_string(a) + " = " + to_string(b) + " / " + to_string(c);
}

void solve()
{
    int t;
    cin >> t;
    cin.ignore();
    string s;
    while (t--)
    {
        getline(cin, s);
        vector<string> token;
        stringstream ss(s);
        string temp;
        while (ss >> temp)
        {
            if (temp.size() > 0)
                token.eb(temp);
        }
        // 0 2 4

        a1 = num(token[0]);
        a2 = num(token[2]);
        a3 = num(token[4]);
        bool f = 0;
        // ? =
        if (token[3] == "=")
        {
            if (token[1] == "?")
            {
                for (int i = 1; i <= 4; i++)
                {
                    for (auto j : a1)
                    {
                        for (auto k : a2)
                        {
                            for (auto l : a3)
                            {
                                if (check(j, k, l, i))
                                {
                                    cout << format(j, k, l, i) << endl;
                                    f = 1;
                                    break;
                                }
                            }
                            if (f)
                                break;
                        }
                        if (f)
                            break;
                    }
                    if (f)
                        break;
                }
            }
            else
            {
                int o = 1;
                if (token[1] == "+")
                    o = 1;
                else if (token[1] == "-")
                    o = 2;
                else if (token[1] == "*")
                    o = 3;
                else
                    o = 4;
                for (auto j : a1)
                {
                    for (auto k : a2)
                    {
                        for (auto l : a3)
                        {
                            if (check(j, k, l, o))
                            {
                                cout << format(j, k, l, o) << endl;
                                f = 1;
                                break;
                            }
                        }
                        if (f)
                            break;
                    }
                    if (f)
                        break;
                }
            }
        }
        // = ?
        else if (token[1] == "=")
        {
            if (token[3] == "?")
            {
                for (int i = 1; i <= 4; i++)
                {
                    for (auto j : a1)
                    {
                        for (auto k : a2)
                        {
                            for (auto l : a3)
                            {
                                // a ? b = c

                                if (check(l, k, j, i))
                                {
                                    cout << format1(j, k, l, i) << endl;
                                    f = 1;
                                    break;
                                }
                            }
                            if (f)
                                break;
                        }
                        if (f)
                            break;
                    }
                    if (f)
                        break;
                }
            }
            else
            {
                int o = 1;
                if (token[3] == "+")
                    o = 1;
                else if (token[3] == "-")
                    o = 2;
                else if (token[3] == "*")
                    o = 3;
                else
                    o = 4;
                for (auto j : a1)
                {
                    for (auto k : a2)
                    {
                        for (auto l : a3)
                        {
                            if (check(l, k, j, o))
                            {
                                cout << format1(j, k, l, o) << endl;
                                f = 1;
                                break;
                            }
                        }
                        if (f)
                            break;
                    }
                    if (f)
                        break;
                }
            }
        }
        else
        {
            for (int i = 1; i <= 4; i++)
            {
                for (auto j : a1)
                {
                    for (auto k : a2)
                    {
                        for (auto l : a3)
                        {
                            if (check(j, k, l, i))
                            {
                                cout << format(j, k, l, i) << endl;
                                f = 1;
                                break;
                            }
                        }
                        if (f)
                            break;
                    }
                    if (f)
                        break;
                }
                if (f)
                    break;
            }
            if (!f)
            {
                for (int i = 1; i <= 4; i++)
                {
                    for (auto j : a1)
                    {
                        for (auto k : a2)
                        {
                            for (auto l : a3)
                            {
                                if (check(l, k, j, i))
                                {
                                    cout << format1(j, k, l, i) << endl;
                                    f = 1;
                                    break;
                                }
                            }
                            if (f)
                                break;
                        }
                        if (f)
                            break;
                    }
                }
            }
        }

        if (!f)
            cout << "WRONG PROBLEM!\n";
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