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

void trunghieu()
{
	vi final;
	final.pb(1);
	final.pb(2);
	final.pb(3);
	final.pb(8);
	final.pb(0);
	final.pb(0);
	final.pb(4);
	final.pb(7);
	final.pb(6);
	final.pb(5);
	vi a(10);
	int i,x;
	forn(i,10)
		cin>>a[i];
	queue<vi> q;
	map<vi,int> visited;
	q.push(final);
	visited[final] = 1;
	map<vi,int> change;
	int left = 0, right = 0;
	while(!q.empty())
	{
		vi u = q.front();
		q.pop();
		if(u == a)
		{
			int x = change[u]%6;
			cout<<left * (6 - x) + right * (6 - x);
			return;
		}
		vi u1 = u, u2 = u;
		u1[0] = u[3];u1[1] = u[0];u1[3] = u[7];
		u1[5] = u[1];u1[7] = u[8];u1[8] = u[5];
		//

		u2[1] = u[4]; u2[2] = u[1];u2[4] = u[8];
		u2[6] = u[2]; u2[8] = u[9]; u2[9] = u[6];
		if(visited[u2] == 0)
		{
			q.push(u2);
			visited[u2] = 1;
			change[u2] = change[u] + 1;
			left++;
			if(u2 == a)
			{
				int x = change[u2]%6;
				cout<<left * (6 - x) + right * (6 - x);
				return;
			}
		}
		if(visited[u1] == 0)
		{
			q.push(u1);
			visited[u1] = 1;
			change[u1] = change[u] + 1;
			right++;
			if(u1 == a)
			{
				int x = change[u1]%6;
				cout<<left * (6 - x) + right * (6 - x);
				return;
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
   	trunghieu();
    return 0;
}