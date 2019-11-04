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

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

void trunghieu()
{
    int n, m, d;
    cin>>n>>m>>d;
    int i,j, ans = 0;
    vector<pair<int,int>> a(n);
    forn(i,n)
    {
    	cin>>a[i].first;
    	a[i].second = i;
    }
    sort(begin(a), end(a));
    int cnt = 1;
    gp_hash_table<int,int, chash> visited, day;
    forn(i,n){
    	if(!visited[a[i].second]){
    		int begin = a[i].first;
    		day[a[i].second] = cnt;
    		while(begin <= m){
    			int id = lower_bound(a.begin() + i, a.end(), make_pair(begin + d + 1, numeric_limits<int>::min())) - a.begin();
    			if(id >= a.size())
    				break;
    			while(visited[a[id].second] && id < a.size())
    				id++;
    			if(id >= a.size())
    				break;
	    		day[a[id].second] = cnt;
	    		visited[a[id].second] = 1;
    			begin = a[id].first;
    		}
    		cnt++;
    	}
    }
    cout<<cnt-1<<endl;
    forn(i,n)
    	cout<<day[i]<<" ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    trunghieu();
    return 0;
}