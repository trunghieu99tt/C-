#include <bits/stdc++.h>

#define forn(i, n) for (i = 0; i < n; ++i)

#define for1(i, n) for (i = 1; i <= n; ++i)

#define pb push_back

#define all(x) (x).begin(), (x).end()

#define mp make_pair

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<vi> vvi;

typedef vector<vll> vvll;

typedef vector<string> vs;

typedef vector<vs> vvs;

int main()

{

    ios::sync_with_stdio(false);

    cin.tie();

    //freopen("input.txt","r",stdin);

    //freopen("output.txt","w",stdout);

    int n, s;

    cin >> n >> s;

    int ans = 0;

    while (1)

    {

        while (s < n)

            n--;

        ans += (s / n);

        s -= n * (s / n);

        n--;

        if (s == 0)

        {

            cout << ans;

            return 0;
        }
    }

    return 0;
}