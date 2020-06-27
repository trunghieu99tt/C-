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

/* Extend Euclid: ax + by = c;
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/
/*--------------------------------------------------------------------------------------------------*/

const int maxn = 1e5;

int n, a[maxn];

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int i,j;
		forn(i,n)
			cin>>a[i];
		int s = 0, e = n-1, maxV, minV;
		forn(s,n)
		{
			if(a[s] > a[s+1])
				break;
		}
		if(s == n-1)
		{
			cout<<"YES\n";break;
		}
		else
		{
			for(e = n-1;e>0;e--)
			{
				if(a[e] < a[e-1])
					break;
			}
			maxV = a[s]; minV = a[s];
			for(i = s+1;i<=e;i++)
			{
				maxV = max(maxV, a[i]);
				minV = min(minV, a[i]);
			}
			for(i = 0;i<s;i++)
			{
				if(a[i] > minV)
				{
					s = i;
					break;
				}
			}
			for(i = n-1;i>e;i--)
			{
				if(a[i] < maxV)
				{
					e = i;
					break;
				}
			}
			int x = e - s + 1;
			if(x == 0)
				cout<<"YES\n";
			else cout<<x<<endl;
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     //freopen("output.txt","w",stdout);
    // #endif
    trunghieu();
    return 0;
}