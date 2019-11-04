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

int calc(int a[], int n, int x)

{

    int ans = 0, i;

    forn(i, n)

    {

        if (abs(a[i] - x) > 1)

            ans += abs(a[i] - x) - 1;
    }

    return ans;
}

int main()

{

    ios::sync_with_stdio(false);

    cin.tie();

    //freopen("input.txt","r",stdin);

    //freopen("output.txt","w",stdout);

    int n;

    cin >> n;

    int a[n], i, sum = 0;

    forn(i, n)

    {

        cin >> a[i];

        sum += a[i];
    }

    sum /= n;

    int ans = INT_MAX, res;

    for (i = 1; i <= 101; i++)

    {

        int temp = calc(a, n, i);

        if (temp < ans)

        {

            ans = temp;

            res = i;
        }
    }

    cout << res << " " << ans << endl;

    return 0;
}