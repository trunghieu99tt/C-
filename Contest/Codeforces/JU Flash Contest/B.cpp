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

int x[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin>>n>>m;
    vll a(n+1);
    vll b(n);
    bool f = true;


    for(int i=1; i<=n; ++i){
    	cin>>a[i];
    	if(i!=1){
    		if(abs(a[i]- a[i-1])%m ==0) f= false;
    	}
    }
    for(int i=0; i<n; ++i){
    	cin>>b[i];
    }

    if(!f || n==1){
    	cout<<0;
    	return 0;
    }

    int ans = 0;
    int d = n;
    for(int i= 0; i<n; ++i){
    	d--;
    	ans ++;
    	if(d==1) break;
    	x[b[i]]=1;
    	int st=b[i]-1, e = b[i]+1;
    	while(st>0 && x[st]==1) st--;
    	while(e<=n && x[e]==1) e++;
    	if(st>0 && e<=n){
    		if(abs(a[st] - a[e]) % m==0){
	    		break;
	    	}
    	}
    }
    cout<<ans;

    return 0;
}