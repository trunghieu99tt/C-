#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;

ll binPow(int a, int b)
{
	ll x = 1, y = a;
	while(b)
	{
		if(b&1)
			x = (x * y)%mod;
		y = (y*y)%mod;
		b>>=1;
	}
	return x%mod;
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
    	int n, k;
    	cin>>n>>k;
    	cout<<binPow(n,k)<<endl;
    }
    return 0;
}