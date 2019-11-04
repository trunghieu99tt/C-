#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

#define forn(i, n) for (i = 0; i < n; ++i)

#define for1(i, n) for (i = 1; i <= n; ++i)

#define eb emplace_back

#define all(x) (x).begin(), (x).end()

#define fill(x, b) memset((x), b, sizeof((x)))

#define fill2D(x, r, c, b) memset((x), b, sizeof(x[0][0]) * r * c)

#define whatIs(a) cout << #a << " is : " << a << endl

typedef long long ll;

typedef vector<ll> vi;

typedef vector<ll> vll;

typedef vector<vi> vvi;

typedef vector<vll> vvll;

typedef vector<string> vs;

typedef vector<vs> vvs;

const ll mod = 1e9 + 7;

clock_t t1, t2;

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

ll inverserEuler(ll n) { return binPow(n, mod - 2); }

ll C(ll k, ll n)
{
	vll f(n + 1, 1);
	for (ll i = 2; i <= n; i++)
		f[i] = (f[i - 1] * i) % mod;
	return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n - k])) % mod) % mod) % mod;
}

/* Extend Euclid: ax + by = c;

ll x, y;



void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}

// nghiem : x + (b/d)*k, y - (a/d) * k;

*/

/*--------------------------------------------------------------------------------------------------*/

const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

struct chash
{

	ll operator()(ll x) const { return x ^ RANDOM; }
};

void trunghieu()

{

	int q;

	cin >> q;

	while (q--)
	{

		int n;

		cin >> n;

		ll a[n], i, j;

		map<ll, int> cnt;

		forn(i, n)

				cin >>
			a[i],
			cnt[a[i]]++;

		int flag = 0;

		for (auto i : cnt)
		{

			if (i.first == 2048)
			{

				flag = 1;

				break;
			}
			else
			{

				if (i.first < 2048)
				{

					if (i.second >= 2)
					{

						cnt[i.first * 2] += i.second / 2;
					}
				}
			}
		}

		if (flag)

			cout << "YES\n";

		else
			cout << "NO\n";
	}
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