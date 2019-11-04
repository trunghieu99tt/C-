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

bool checkPrime(ll n)

{

    if (n < 2)

        return 0;

    if (n <= 3)

        return 1;

    if (n % 2 == 0 || n % 3 == 0)

        return 0;

    ll i = 5;

    while (i * i <= n)

    {

        if (n % i == 0 || n % (i + 2) == 0)

            return 0;

        i += 6;
    }

    return 1;
}

bool checker(ll n)

{

    if (n < 2)

        return 0;

    ll x = sqrt(n);

    if (x * x == n && checkPrime(x))

        return 1;

    return 0;
}

int main()

{

    ios::sync_with_stdio(false);

    cin.tie();

    //freopen("input.txt","r",stdin);

    //freopen("output.txt","w",stdout);

    int n, i;

    cin >> n;

    ll a[n];

    forn(i, n)

    {

        cin >> a[i];

        if (checker(a[i]))

            printf("YES\n");

        else
            printf("NO\n");
    }

    return 0;
}