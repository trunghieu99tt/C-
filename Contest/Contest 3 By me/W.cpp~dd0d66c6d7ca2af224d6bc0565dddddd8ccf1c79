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
    	int i,j,l;
    	ll ans[n+1][k+1];
    	memset(ans,0,sizeof(ans));
    	for1(i,min(9,k))
    		ans[1][i] = 1;
    	for(i = 2;i<=n;i++)
    		for1(j,k)
    			forn(l,10)
    				if(j - l >=0)
    				ans[i][j]+= ans[i-1][j-l]%mod;
    	ll finalAns = (ans[n][k] + mod)%mod;
    	cout<<finalAns<<endl;
    }
    return 0;
}