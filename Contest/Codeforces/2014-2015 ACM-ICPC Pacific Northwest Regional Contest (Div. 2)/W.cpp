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

const ll inf = 1e18;

typedef struct Data
{
    string name;
    double x, y, z;
} dt;

double calc(dt a, dt b)
{
    double x1 = a.x - b.x, x2 = a.y - b.y, x3 = a.z - b.z;
    return sqrt(x1*x1 + x2*x2 + x3 * x3);
}

ll rounder(double x)
{
    ll y = x;
    x-=y;
    if(x < 0.5)
        return y;
    return y + 1;
}

const int maxn = 105;

dt f[maxn];

void trunghieu()
{
    int t;
    cin>>t;
    int test = 1;
    while(t--)
    {
    	int n;
    	cin>>n;
    	map<pair<string,string>, double> dist;
    	int i,j,k;
    	string name;
    	ll x, y, z;
    	forn(i,n)
            cin>>f[i].name>>f[i].x>>f[i].y>>f[i].z;
    	int w;
    	cin>>w;
    	forn(i,n)
            for(j = i + 1;j<n;j++)
                dist[{f[i].name,f[j].name}] = dist[{f[j].name,f[i].name}] = calc(f[i], f[j]);
    	forn(i,w)
    	{
    		string in, out;
    		cin>>in>>out;
    		dist[{in,out}] = 0;
    	}
        forn(k,n) forn(i,n) forn(j,n) 
        dist[{f[i].name, f[j].name}] 
        = min(dist[{f[i].name, f[j].name}], dist[{f[i].name, f[k].name}] + dist[{f[k].name, f[j].name}]);
    	int q;
    	cin>>q;
    	cout<<"Case "<<test++<<":\n";
    	forn(i,q)
    	{
    		string source, dest;
    		cin>>source>>dest;
    		cout<<"The distance from "<<source<<" to "<<dest<<" is "<<rounder(dist[{source, dest}])<<" parsecs.\n";
    	}
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