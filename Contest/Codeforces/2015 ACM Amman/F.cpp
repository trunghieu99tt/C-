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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;
clock_t t1,t2;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

ll inverserEuler(int n){return binPow(n, mod-2);}

ll C(int k, int n){vll f(n+1,1);for(int i = 2;i<=n;i++)f[i] = (f[i-1]*i)%mod;return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n-k]))%mod)%mod)%mod;}

/* Extend Euclid: ax + by = c;
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/
/*--------------------------------------------------------------------------------------------------*/

typedef pair<int,int> pii;

struct chash{
	int operator()(pii x) const{
		return x.first * 31 + x.second;
	}
};

void trunghieu()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n, m;
    	cin>>n>>m;
    	vi nodes;
    	int i,j;
    	for1(i,n)
    		nodes.eb(i);
    	vi length;
    	int a,b,c;
    	gp_hash_table<int,vi> adjList;
    	gp_hash_table<int,int> visited;
    	gp_hash_table<pii,int, chash> ways;
    	int ans = 0;
    	forn(i,m)
    	{
    		cin>>a>>b>>c;
    		ways[{a,b}] = c;
    		ways[{b,a}] = c;
    		adjList[a].eb(b);
    		adjList[b].eb(a);
    	}
    	for1(i,n)
    	{
    		if(adjList[i].size() == 1)
    			ans = max(ans, ways[{i,adjList[i][0]}]);
    		else
    		{
    			int tmp = INT_MAX;
    			for(auto j:adjList[i])
    				tmp = min(tmp, ways[{i,j}]);
    			ans = max(ans, tmp);
    		}
    	}
    	cout<<ans<<endl;
    }
}

int main()
{
    cerr << "Program is running" << endl;
    t1 = clock();
    ios::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    trunghieu();
    t2 = clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cerr << "\nRunning in " << seconds << " seconds" << endl;
    return 0;
}