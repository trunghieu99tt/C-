#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

ll a, b, c, f2, f3, f4, l, r;
const int mod = 1e9 + 7;

ll binPow(ll a, ll b)
{
	ll x = 1, y = a;
	while (b)
	{
		if (b & 1)
			x = (x * y) % mod;
		y = (y*y) % mod;
		b >>= 1;
	}
	return x % mod;
}

bool checkSquare(ll n)
{
	ll num = sqrt(n);
	return num * num == n;
}

vll solveQuadratic(ll b, ll c)
{
	vll ans;
	ll delta = b * b - 4 * c;
	if (delta <= 0 || !checkSquare(delta))
		return {};
	double x1 = (-b + sqrt(delta)) / 2.0, x2 = (-b - sqrt(delta)) / 2.0;
	if (x1 > 0.0 && ll(x1) == x1)
		ans.pb(x1);
	if (x2 > 0.0 && ll(x2) == x2)
		ans.pb(x2);
	return ans;
}


bool check(ll a)
{
	ll x = f2 - a*a, y = f3 - a*a*a, z = f4 - a*a*a*a;
	if (x <= 0 || y <= 0 || z <= 0)
		return 0;
	// k2 = b^2*c^2 = ((b^2 + c^2)^2 - b^4 - c^4))/2
	if (!checkSquare((x*x - z)/2) || (x*x-z)%2)
		return 0;
	ll k2 = (x*x - z) / 2;
	k2 = sqrt(k2);
	// k1 = (b+c)^2 = (b^2 + c^2 + 2sqrt(k2));
	ll k1 = x + 2 * k2;
	if (!checkSquare(k1))
		return 0;
	k1 = sqrt(k1);
	// Quadratic: x^2 - (b+c)x + bc
	vll ans = solveQuadratic(-k1, k2);
	if (ans.size() < 2)
		return 0;
	b = min(ans[0],ans[1]); c = max(ans[1],ans[0]);
	if (a*a*a + b*b*b + c*c*c != f3 || a == b || a == c
		|| a*a + b*b + c*c != f2 || a*a*a*a + b*b*b*b + c*c*c*c!=f4)
		return 0;
	return 1;
}

ll calc(ll x, ll left, ll right)
{
	if (x == 1)
		return right - left + 1;
	return ((binPow(x, right + 1) - binPow(x, left) + mod) % mod * binPow(x - 1, mod - 2) % mod);
}

void show()
{
	ll ans = 0;
	ans = (calc(a, l, r) + calc(b, l, r) + calc(c, l, r)) % mod;
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> f2 >> f3 >> f4 >> l >> r;
		for (a = 1;a <= min(f2, 15000ll);a++)
		{
			if (check(a))
			{
				show();
				break;
			}
		}
	}
	return 0;
}
