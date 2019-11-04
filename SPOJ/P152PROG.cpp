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

void solve(vi &a, int x)
{
	if(x==a.size()-1) return;
	else 
	{
		solve(a,x+1);
		swap(a[x],a[x+1]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int i;
	vi a;
	for(i=1;i<=n;i++)
		a.pb(i);
	solve(a,0);
	for(auto i:a)
		cout<<i<<" ";
	return 0;
}
 
