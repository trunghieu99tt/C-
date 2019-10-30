#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

const int maxn = 2e5 + 5;

int n, a[maxn], dp[maxn];

void trunghieu()
{
    int t;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	gp_hash_table<int,vi> index;
    	gp_hash_table<int,int> now;
    	int i,j;
    	forn(i,n)
    	{
    		cin>>a[i];
    		dp[i] = 0;
    		index[a[i]].eb(i);
    	}
    	now[a[0]]++;
    	for1(i,n - 1)
    	{
    		int prev;
    		if(now[a[i]] == 0)
    			prev = -1;
    		else 
    			prev = index[a[i]][now[a[i]] - 1];
    		//cout<<a[i]<<" "<<prev<<" "<<now[a[i]]<<endl;
    		if(prev == -1)
    			dp[i] = dp[i - 1] + 1;
    		else dp[i] = min(dp[i-1] + 1, dp[prev] + 1);
    		now[a[i]]++;
    	}
    	// forn(i,n)
    	// 	cout<<dp[i]<<" ";
    	// cout<<endl;
    	cout<<dp[n-1]<<endl;
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