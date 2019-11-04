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
	int n;
	cin>>n;
	int a[n],b[n],i,j;
	forn(i,n)
		cin>>a[i];
	forn(i,n)
		cin>>b[i];
	int maxa = *max_element(a,a+n), maxb = *max_element(b,b+n);
	if(maxb > maxa)
	{
		bool flag=1;
		forn(i,n)
			if(a[i]%maxb!=b[i])
			{
				flag=0;
				break;
			}
		if(flag) cout<<maxb;
		else cout<<-1;
	}
	else if(maxb < maxa)
	{
		for1(i,maxa)
		{
			bool flag=1;
			forn(j,n)
				if(a[j]%i!=b[j])
				{
					flag=0;
					break;
				}
			if(flag)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<-1;
	}
	else 
	{
		bool flag=1;
		forn(i,n)
			if(a[i]!=b[i])
				{
					flag=0;
					break;
				}
		if(flag) cout<<maxa+1;
		else cout<<-1;
	}
	return 0;
}
