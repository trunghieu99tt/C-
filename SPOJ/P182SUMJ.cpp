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

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	n*=2;
	vi a,b,v;
	int i,temp;
	forn(i,n)
	{
		cin>>temp;
		v.pb(temp);
	}
	int f =0,f1 = 1;
	forn(i,n)
	{
		a.pb(f);
		f=1-f;
		b.pb(f1);
		f1=1-f1;
	}
	int countera = 0, counterb=0;
	forn(i,n)
	{
		if(a[i]!=v[i]) countera++;
		if(b[i]!=v[i]) counterb++;
	}
	cout<<min(countera/2,counterb/2);
	return 0;
} 
