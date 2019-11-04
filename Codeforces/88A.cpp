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

/* Extend Euclid: ax + by = c; */

// ll x, y;

// void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}

// nghiem : x + (b/d)*k, y - (a/d) * k;

/*--------------------------------------------------------------------------------------------------*/

vector<string> notes{

    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H",

    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

int dist(string a, string b)

{

    int idA = -1, idB = -1, i;

    forn(i, notes.size())

    {

        if (notes[i] == a)

            idA = i;

        else if (notes[i] == b && idA != -1)

            return i - idA;
    }

    return 0;
}

bool checkMijor(vs a)

{

    sort(all(a));

    do

    {

        // cout << a[0] << " " << a[1] << " " << a[2] << endl;

        // cout << dist(a[0], a[1]) << " " << dist(a[1], a[2]) << endl;

        if (dist(a[0], a[1]) == 4 && dist(a[1], a[2]) == 3)

        {

            return 1;
        }

    } while (next_permutation(all(a)));

    return 0;
}

bool checkMinor(vs a)

{

    sort(all(a));

    do

    {

        // cout << a[0] << " " << a[1] << " " << a[2] << endl;

        // cout << dist(a[0], a[1]) << " " << dist(a[1], a[2]) << endl;

        if (dist(a[0], a[1]) == 3 && dist(a[1], a[2]) == 4)

        {

            return 1;
        }

    } while (next_permutation(all(a)));

    return 0;
}

void trunghieu()

{

    vs a(3);

    int i;

    forn(i, 3)

            cin >>

        a[i];

    if (checkMijor(a))

        cout << "major";

    else if (checkMinor(a))

        cout << "minor";

    else

        cout << "strange";

    return;
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
