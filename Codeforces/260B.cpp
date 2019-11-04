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

/* Extend Euclid: ax + by = c;

ll x, y;

 

void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}

// nghiem : x + (b/d)*k, y - (a/d) * k;

*/

/*--------------------------------------------------------------------------------------------------*/

bool checkDay(int day, int month)

{

    switch (month)

    {

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:

        return day <= 31 && day >= 1;

    case 4:
    case 6:
    case 9:
    case 11:

        return day <= 30 && day >= 1;

    case 2:

        return day <= 28 && day >= 1;
    }

    return 0;
}

void trunghieu()

{

    string s;

    cin >> s;

    vs split;

    stringstream ss(s);

    string token;

    while (getline(ss, token, '-'))

        split.pb(token);

    int i, j, n = split.size();

    map<string, int> cnt;

    // for(auto i:split)

    //     cout<<i<<endl;

    for (i = 0; i < n - 2; i++)

    {

        string date = "";

        int day, month, year;

        if (split[i].size() >= 2 && split[i + 1].size() == 2 && split[i + 2].size() >= 4)

        {

            if (split[i].size() == 2)

                date += split[i];

            else
                date += split[i].substr(split[i].size() - 2);

            day = stoi(date);

            date += "-";

            month = stoi(split[i + 1]);

            date += split[i + 1];

            date += "-";

            year = stoi(split[i + 2].substr(0, 4));

            date += split[i + 2].substr(0, 4);
        }

        //out<<day<<" "<<month<<" "<<year<<" "<<checkDay(day,month)<<endl;

        if (date != "" && year >= 2013 && year <= 2015 && month >= 1 && month <= 12

            && checkDay(day, month))

            cnt[date]++;
    }

    map<int, vs, greater<int>> ans;

    for (auto i : cnt)

    {

        ans[i.second].pb(i.first);

        //cout<<i.first<<" : "<<i.second<<endl;
    }

    map<int, vs, greater<int>>::iterator it;

    it = ans.begin();

    cout << it->second[0];
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