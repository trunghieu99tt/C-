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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	int n,k,i,temp;
	cin>>n>>k;
	vi a;
	forn(i,n)
	{
		cin>>temp;
		a.pb(temp);
	}
	vi b = a,res;
	sort(all(b),greater<int>());
	int lim = b[k-1],counter = 0;
	for(auto i:a)
		if(i>lim) counter++;
	forn(i,n)
	{
		if(a[i] > lim)
		{
			res.pb(i+1);
			counter--;
			k--;
		}
		else if(a[i] == lim)
		{
			if(counter < k)
			{
				res.pb(i+1);
				k--;
			}
		}
	}
	cout<<lim<<endl;
	for(auto i:res)
		cout<<i<<" ";
	return 0;
}
