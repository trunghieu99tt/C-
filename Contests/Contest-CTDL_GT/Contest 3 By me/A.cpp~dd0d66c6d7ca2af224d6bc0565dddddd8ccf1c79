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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    int coins[] = {1000, 500,200,100,50,20,10,5,2,1};
    while(t--)
    {
    	int n;
    	cin>>n;
    	int i = 0, ans = 0;
    	while(n>0)
    	{
    		while(coins[i] > n)
    			i++;
    		int add = n/coins[i];
    		ans+=add;
    		n-= (add * coins[i]);
    		i++;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}