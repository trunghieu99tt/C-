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
    	int n, m, k;
    	cin>>n>>m>>k;
    	string a, b;
    	cin>>a>>b;
    	int i,j, ans = 0;
    	vector<pair<char,char>> firstLast;
    	map<pair<char,char>, int> exitst;
    	forn(i, a.size() - k + 1)
    	{
    		if(!exitst[{a[i], a[i+k - 1]}])
    			firstLast.pb({a[i],a[i+k - 1]}),
    			exitst[{a[i], a[i+k - 1]}] = 1;
    	}
    	map<char,vi> index;
    	forn(i,b.size())
    		index[b[i]].pb(i);
    	for(auto i:firstLast)
           ans+= (index[i.first].size() + 1) * (index[i.first].size())/2;
    	cout<<ans<<endl;
    }
    return 0;
}