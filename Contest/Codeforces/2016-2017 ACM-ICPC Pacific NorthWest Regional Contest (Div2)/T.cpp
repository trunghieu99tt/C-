#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

ll inverserEuler(int n){return binPow(n, mod-2);}

ll C(int k, int n){vll f(n+1,1);for(int i = 2;i<=n;i++)f[i] = (f[i-1]*i)%mod;return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n-k]))%mod)%mod)%mod;}

/* Extend Euclid: ax + by = c; */
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;

/*--------------------------------------------------------------------------------------------------*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	//freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    char a[n][m];
    int i,j;
    forn(i,n)
    	forn(j,m)
    		cin>>a[i][j];
    int dr[] = {-1,0,0,1},
    	dc[] = {0,-1,1,0},cnt = 0;
    forn(i,n)
    {
    	forn(j,m)
    	{
    		if(a[i][j] == 'L')
    		{
    			cnt++;
    			queue<pair<int,int>> q;
    			q.push({i,j});
    			while(!q.empty())
    			{
    				pair<int,int> u = q.front();
    				q.pop();
    				int x = u.first, y = u.second;
    				for(int k = 0;k<4;k++)
    				{
    					int x1 = x + dr[k], y1 = y + dc[k];
    					if(x1 >=0 && y1 >=0 && x1 < n && y1 < m && (a[x1][y1] == 'L' || a[x1][y1] == 'C'))
    					{
    						a[x1][y1] = 'W';
    						q.push({x1,y1});
    					}
    				}
    			}
    		}
    	}
    }
    cout<<cnt;
    return 0;
}