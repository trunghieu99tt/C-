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

/*---------------------------------------------------------------------------------------*/

ll preSolve(int n, int k)
{
	ll res[n];
	res[0] = 1;res[1] = 1;
	for(int i = 2;i<n;i++)
	{
		res[i] = 0;
		for(int j = 1; j<=k && j <= i;j++)
		{
			res[i]+= res[i-j];
			res[i]%=mod;
		}
	}
	return res[n-1];
}

ll solve(int n, int k)
{
	return preSolve(n+1,k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
    	int n,k;
    	cin>>n>>k;
    	cout<<solve(n,k)<<endl;
    }
    return 0;
}