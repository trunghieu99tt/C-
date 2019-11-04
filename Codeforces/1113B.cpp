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

    int n;

    cin >> n;

    int a[n], i, j;

    forn(i, n)

            cin >>
        a[i];

    sort(a, a + n);

    int ans = accumulate(a, a + n, 0), sum = ans;

    for (i = 0; i < n; i++)

    {

        for (int j = 2; j * j <= a[i]; j++)

        {

            if (a[i] % j == 0)

                ans = min(ans, sum - a[i] - a[0] + a[i] / j + a[0] * j);
        }
    }

    cout << ans;

    return 0;
}