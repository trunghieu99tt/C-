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

    int t, k;

    cin >> t;

    forn(k, t)

    {

        int l1, r1, l2, r2;

        cin >> l1 >> r1 >> l2 >> r2;

        int a, b;

        a = r1;
        b = r2;

        while (a == b)
        {

            if (a - 1 >= l1)

                a--;

            else if (b - 1 >= l2)

                b--;
        }

        cout << a << " " << b << endl;
    }

    return 0;
}