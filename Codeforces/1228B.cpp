#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/trie_policy.hpp>

#include <ext/pb_ds/tag_and_trait.hpp>

using namespace __gnu_pbds;

using namespace std;

/*--------------------------------- USER'S DEFINE -----------------------------------------*/

#define forn(i, n) for (i = 0; i < n; ++i)

#define for1(i, n) for (i = 1; i <= n; ++i)

#define eb emplace_back

#define all(x) (x).begin(), (x).end()

#define fill(x, b) memset((x), b, sizeof((x)))

#define fill2D(x, r, c, b) memset((x), b, sizeof(x[0][0]) * r * c)

#define whatIs(a) cout << #a << " is : " << a << endl

/*--------------------------------- USER'S TYPEDEF -----------------------------------------*/

typedef long long ll;

typedef vector<ll> vi;

typedef vector<ll> vll;

typedef vector<vi> vvi;

typedef vector<vll> vvll;

typedef vector<string> vs;

typedef vector<vs> vvs;

typedef pair<int, int> pii;

clock_t t1, t2;

/*---------------------------------POLICY-BASED-DATA STRUCTURES -------------------------------*/

// Set up chash for hash table

ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();

ll SEED = ll(new ll);

ll RANDOM = TIME ^ SEED;

ll MOD = (int)1e9 + 7;

ll MUL = (int)1e6 + 3;

// optionn 1 (slower - don't know why)

//struct chash{

//  ll operator()(ll x) const {return std::hash<ll>{}((x^RANDOM)%MOD * MUL);}

//};

struct chash
{

	int operator()(int x) const { return x ^ RANDOM; }
};

// Set up trie

typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> trie;

// Set up Red-Black Tree

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rb_tree;

/*-----------------------------------USEFUL FUNCS -----------------------------------------------*/

ll binPow(ll a, ll b)
{
	ll x = 1, y = a;
	while (b)
	{
		if (b & 1)
			x = (x * y) % MOD;
		y = (y * y) % MOD;
		b >>= 1;
	}
	return x % MOD;
}

ll inverserEuler(ll n) { return binPow(n, MOD - 2); }

ll C(ll k, ll n)
{
	vll f(n + 1, 1);
	for (ll i = 2; i <= n; i++)
		f[i] = (f[i - 1] * i) % MOD;
	return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n - k])) % MOD) % MOD) % MOD;
}

/* Extend Euclid: ax + by = c;

ll x, y;

 

void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}

// nghiem : x + (b/d)*k, y - (a/d) * k;

*/

/*--------------------------------- USER'S SOLVE FUNC -------------------------------------------*/

void trunghieu()

{

	int h, w, i, j;

	cin >> h >> w;

	vi r(h + 1), c(w + 1);

	vvi board(h + 1, vi(w + 1, 0));

	for1(i, h)

	{

		cin >> r[i];

		for1(j, r[i])
		{

			board[i][j] = 1;
		}
	}

	for1(i, w)

	{

		cin >> c[i];

		for1(j, c[i])

			board[j][i] = 1;
	}

	int ans = 0;

	for1(i, h)
	{

		for1(j, w)
		{

			if (board[i][j] == 0)
			{

				if (j > r[i] + 1 && i > c[j] + 1)

					ans++;
			}
		}
	}

	for1(i, h)
	{

		int checkR = 0;

		for1(j, w)
		{

			if (board[i][j] == 1)

				checkR++;

			else
				break;
		}

		if (checkR != r[i])
		{

			cout << 0;

			return;
		}
	}

	for1(j, w)
	{

		int checkC = 0;

		for1(i, h)
		{

			if (board[i][j] == 1)

				checkC++;

			else
				break;
		}

		if (checkC != c[j])
		{

			cout << 0;

			return;
		}
	}

	cout << binPow(2, ans);
}

/*--------------------------------- MAIN FUNC ---------------------------------------------------*/

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
