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

bool check(vi a)
{
	ll ans = 0;
	for(int i = 0;i<a.size();i++)
		ans+=a[i];
	return ans%3 == 0;
}

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int i,j;
		vvi num(3);
		vi ans;
		forn(i,n)
		{
			cin>>a[i];
			if(a[i]%3 == 0)
				ans.pb(a[i]);
			else num[a[i]%3].pb(a[i]);
		}
		i = 0;j = 0;
		sort(all(num[1]), greater<int>());
		sort(all(num[2]), greater<int>());
		int n1 = num[1].size(), n2 = num[2].size();
		forn(i,num[1].size() - num[1].size()%3)
			ans.pb(num[1][i]);
		forn(i,num[2].size() - num[2].size()%3)
			ans.pb(num[2][i]);
		i = num[1].size() - num[1].size()%3;
		j = num[2].size() - num[2].size()%3;
		while(i < n1 && j < n2)
		{
			if(i < n1 && j < n2)
			{
				ans.pb(num[1][i]);
				ans.pb(num[2][j]);
			}
			i++;
			j++;
		}
		if(ans.empty())
			cout<<-1<<endl;
		else
		{
			sort(all(ans),greater<int>());
			if(ans[0] == 0)
				cout<<0<<endl;
			else
			{
				forn(i,ans.size())
					cout<<ans[i];
				cout<<endl;
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    trunghieu();
    return 0;
}