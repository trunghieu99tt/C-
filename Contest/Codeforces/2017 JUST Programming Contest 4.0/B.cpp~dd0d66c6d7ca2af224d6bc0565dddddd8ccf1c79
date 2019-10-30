#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

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

const int maxn = 1e4;

int n, m, a[maxn], b[maxn];

void trunghieu()
{
    int t;
    cin>>t;
    while(t--)
    {
    	cin>>n>>m;
    	int i,j;
    	vi index;
    	forn(i,n)
    	{
    		cin>>a[i];
    		if(a[i]!=-1)
    			index.eb(i);
    	}
    	for(auto i:index)
    	{
    		int l = i - 1, r = i + 1;
    		while(a[l] == -1 && l >= 0)
    		{
    			if(a[l+1] == 0)
    				a[l] = (m - 1)%m;
    			else a[l] = (a[l+1] - 1)%m;
    			l--;
    		}
    		while(a[r] == -1 && r < n)
    			a[r] = (a[r - 1] + 1)%m, r++;
    	}
    	forn(i,n)
    		cout<<a[i]<<" ";
    	cout<<endl;
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