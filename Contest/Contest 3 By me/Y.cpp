#include<bits/stdc++.h>

using namespace std;

/*-----------------------------------GENERAL USER's DEFINITION ------------------------------*/
#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

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

ll C(int n, int k){vll f(n+1,1);for(int i = 2;i<=n;i++)f[i] = (f[i-1]*i)%mod;return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n-k]))%mod)%mod)%mod;}

/*---------------------------------------------------------------------------------------*/

const int maxn = 15;

int minCost = INT_MAX, a[maxn][maxn] , visited[maxn], n, tmp = 0;

int cost(int x)
{
	queue<int> q;
	q.push(x);
	int visited[maxn],i, ans = 0;
	memset(visited,0,sizeof(visited));
	visited[x] = 1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(x == 2)
			cout<<u+1<<" ";
		int minCost = INT_MAX , choice, flag = 0;
		for(int i = 0;i<n;i++)
			if(a[u][i]!=0 && a[u][i] < minCost && visited[i] == 0)
			{
				flag = 1;
				choice = i;
				minCost = a[u][i];
			}
		if(flag)
		{
			visited[choice] = 1;
			ans+=minCost;
			q.push(choice);
		}
	}
	if(x == 2)
	cout<<endl;
	return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	int i,j, ans = INT_MAX;
    	forn(i,n)
    		forn(j,n)
    			cin>>a[i][j];
    	forn(i,n)
    	{
    		if(cost(i))
    			ans = min(ans,cost(i));
    		cout<<i<<" "<<cost(i)<<" "<<ans<<endl;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}