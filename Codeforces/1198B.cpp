#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
#define whatIs(a) cout<<#a<<" is : "<<a<<endl

typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const ll mod = 1e9 + 7;
clock_t t1, t2;

ll binPow(ll a, ll b) {ll x = 1, y = a; while (b) {if (b & 1)x = (x * y) % mod; y = (y * y) % mod; b >>= 1;} return x % mod;}

ll inverserEuler(ll n) {return binPow(n, mod - 2);}

ll C(ll k, ll n) {vll f(n + 1, 1); for (ll i = 2; i <= n; i++)f[i] = (f[i - 1] * i) % mod; return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n - k])) % mod) % mod) % mod;}

/* Extend Euclid: ax + by = c;
ll x, y;

void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/
/*--------------------------------------------------------------------------------------------------*/

class SegmentTree { 
private: vi st, A;
	int n;
	int left (int p) { return p << 1; } 
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int L, int R) { // O(n)
		if (L == R) 
			st[p] = L;
		else { 
			build(left(p) , L , (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R );
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
	}
	int rmq(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return -1;
		if (L >= i && R <= j) return st[p];
		int p1 = rmq(left(p) , L , (L + R) / 2, i, j);
		int p2 = rmq(right(p), (L + R) / 2 + 1, R , i, j);
		if (p1 == -1) return p2; 
		if (p2 == -1) return p1; 
		return (A[p1] >= A[p2]) ? p1 : p2; 
	}
public:
	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size(); 
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } 
};

void trunghieu()
{
	int n;
	cin >> n;
	int a[n], i, j;
	forn(i, n)
	cin >> a[i];
	int nq;
	cin >> nq;
	vi q(nq,0);
	vi lastQ(n, -1), lastQIndex(n, 0);
	forn(i, nq) {
		int type;
		cin >> type;
		if (type == 1) {
			int p, x;
			cin >> p >> x;
			p--;
			lastQ[p] = x;
			lastQIndex[p] = i;
		}
		else {
			int x;
			cin >> x;
			q[i] = x;
		}
	}
	SegmentTree st(q);
	forn(i, n) {
		int ans = lastQ[i] == -1 ? a[i] : lastQ[i];
		ans = max(ans, (int)q[st.rmq(lastQIndex[i],nq)]);
		cout << ans << " ";
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