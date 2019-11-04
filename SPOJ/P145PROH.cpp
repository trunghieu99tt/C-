#include<bits/stdc++.h>

#define forn(i,n) for (i=0;i<n;++i)
#define for1(i,n) for (i=1;i<=n;++i)
#define fore(i,l,r) for (i=l;i<=r;++i)
#define ford(i,n) for (i=n-1;i>=0;--i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef double ld;

ll lcm(ll a, ll b)
{
	return a/__gcd(a,b)*b;
}

ll solve(ll a,ll b, ll c)
{
	return lcm(lcm(a,b),c);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	long long res=0;
	int n,i,j,k;
	cin>>n;
	fore(i,max(n-50,1),n)
		fore(j,i,n)
			fore(k,j,n)
				res=max(res,solve(i,j,k));
	cout<<res;	
	return 0;
}
