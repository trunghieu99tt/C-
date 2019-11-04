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

int mod = 1e9+7;
long long solve(long long n)
{
	if(n==1) return 3;
	long long f1=1,f2=3,fn;
	for(int i=2;i<=n;i++)
	{
		fn = 2*f2 + f1;
		fn%=mod;
		f1 = f2;
		f2 = fn;
	}
	return fn;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	long long n;
	cin>>n;
	cout<<solve(n);
	return 0;
} 
