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
	int n,i,j,counter=0;
	cin>>n;
	int a[n],b[n]={0};
	forn(i,n) cin>>a[i];
	sort(a,a+n);
	forn(i,n)
		fore(j,i+1,n-1)
		 if(a[j]>a[i] && !b[j])
		 {
		 	counter++;
		 	b[j]=1;
		 	break;
		 }
	cout<<counter;
	return 0;
}
