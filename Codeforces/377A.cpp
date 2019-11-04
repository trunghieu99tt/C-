#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>

using namespace __gnu_pbds;
using namespace std;

/*--------------------------------- USER'S DEFINE -----------------------------------------*/

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
#define whatIs(a) cout<<#a<<" is : "<<a<<endl


/*--------------------------------- USER'S TYPEDEF -----------------------------------------*/

typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int,int> pii;

clock_t t1, t2;

/*---------------------------------POLICY-BASED-DATA STRUCTURES -------------------------------*/

// Set up chash for hash table

ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
ll SEED = ll(new ll);
ll RANDOM = TIME^SEED;
ll MOD = (int)1e9 + 7;
ll MUL = (int)1e6 + 3;

// optionn 1 (slower - don't know why)
//struct chash{
//  ll operator()(ll x) const {return std::hash<ll>{}((x^RANDOM)%MOD * MUL);}
//};

struct chash{
  int operator()(int x) const{return x^RANDOM;}
};

// Set up trie
typedef trie<string,null_type,trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> trie;

// Set up Red-Black Tree
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rb_tree;

/*-----------------------------------USEFUL FUNCS -----------------------------------------------*/

ll binPow(ll a, ll b) {ll x = 1, y = a; while (b) {if (b & 1)x = (x * y) % MOD; y = (y * y) % MOD; b >>= 1;} return x % MOD;}

ll inverserEuler(ll n) {return binPow(n, MOD - 2);}

ll C(ll k, ll n) {vll f(n + 1, 1); for (ll i = 2; i <= n; i++)f[i] = (f[i - 1] * i) % MOD; return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n - k])) % MOD) % MOD) % MOD;}

/* Extend Euclid: ax + by = c;
ll x, y;

void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/

/*--------------------------------- USER'S SOLVE FUNC -------------------------------------------*/

void trunghieu()
{
	int n,m,k;
	cin>>n>>m>>k;
	char a[n][m];
	vvi visited(n, vi(m,0));
	int i,j, cnt = 0;
	forn(i,n)
		forn(j,m)
			cin>>a[i][j], cnt+= (a[i][j] == '.');
	int dr[] = {-1,0,0,1},
		dc[] = {0,-1,1,0};
	int t = k;
	k = cnt - k;
	forn(i,n)
		forn(j,m){
			if(a[i][j] == '.' && k > 0 && !visited[i][j]){
				queue<pii> q;
				q.push({i,j});
				k--;
				visited[i][j] = 1;
				while(!q.empty() && k > 0){
					auto u = q.front();q.pop();
					for(int l = 0;l<4;l++){
						int x = u.first + dr[l],
							y = u.second + dc[l];
						if(x >=0 && y>=0 && x < n && y < m && a[x][y] == '.' && k > 0 && !visited[x][y]){
							visited[x][y] = 1;
							k--;
							q.push({x,y});
						}
					}
				}
			}
		}
	forn(i,n)
	{
		forn(j,m)
		{
			if(!visited[i][j] && a[i][j] == '.' && t > 0)
				a[i][j] = 'X', t--;
			cout<<a[i][j];
		}
		cout<<endl;
	}
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