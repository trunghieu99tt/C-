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

typedef pair<int,int> pii;

const int maxn = 1e3 + 5;

const int maxN = 1e6 + 1;

struct chash{
	int operator()(pii x) const{
		return x.first*31 + x.second;
	};
};

int a[maxn][maxn], n, m, h, w;

vector<pair<int,int>> indexRev(maxN);
int index[maxn][maxn];

void trunghieu()
{
    cin>>n>>m>>h>>w;
    int i,j, id = 0;
    vi arr;
    forn(i,n)
    	forn(j,m)
    	{
    		cin>>a[i][j];
    		arr.eb(a[i][j]);
    		index[i][j] = id;
    		indexRev[id] = {i,j};
    		id++;
    	}
    int ans = INT_MAX;
    forn(i,n - h + 1)
    {
    	forn(j, m - w + 1)
    	{
    		int b = index[i][j], e = index[i + h - 1][j + w - 1];
    		vi tmp;
    		for(int k = b;k<=e;k++)
    		{
    			pii id = indexRev[k];
    			if(id.first >= i && id.second >= j && id.first <= i + h - 1 && id.second <= j + w - 1)
    				tmp.eb(arr[k]);
    		}
    		// vi tmp;
    		// for(int k = i;k <= i + h - 1;k++)
    		// 	for(int l = j ;l <= j + w - 1;l++)
    		// 		tmp.eb(arr[index[k][l]]);
    		int n1 = tmp.size();
    		nth_element(tmp.begin(),tmp.begin() + n1/2, tmp.end());
    		ans = min(ans, tmp[n1/2]);
    	}
    }
    cout<<ans;
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