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

    ll n, m, k;

    cin >> n >> k >> m;

    int i, a[n];

    ll sum = 0;

    forn(i, n)

            cin >>
        a[i],

        sum += a[i];

    sort(a, a + n);

    ll del = 0, inc = m, num = n;

    long double ans = (sum + min(num * k, inc)) / (long double)(n);

    for (i = 0; i < min(n - 1, m); i++)

    {

        del++;
        inc--;

        num--;
        sum -= a[i];

        if (num >= 1)

            ans = max(ans, (sum + min(num * k, inc)) / (long double)(num * 1.0));
    }

    cout << setprecision(20) << fixed << ans;

    return 0;
}