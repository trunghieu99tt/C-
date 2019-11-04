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

    int a[n], i;

    map<int, int> counter;

    forn(i, n)

    {

        cin >> a[i];

        counter[a[i]]++;
    }

    sort(a, a + n);

    int x = a[n - 1];

    for (i = 1; i * i <= x; i++)

        if (x % i == 0)

        {

            counter[i]--;

            if (x / i != i)

                counter[x / i]--;
        }

    for (i = n - 1; i >= 0; i--)

    {

        if (counter[a[i]] >= 1)

        {

            cout << x << " " << a[i] << endl;

            return 0;
        }
    }

    return 0;
}