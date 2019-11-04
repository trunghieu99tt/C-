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
	int r,c,a,b;
	cin>>r>>c>>a>>b;
	int i,j,f = 1;
	string black="",white="";
	forn(i,b) 
	{
		black+="X";
		white+=".";
	}
	string temp1 = "", temp2="";
	forn(i,c)
	{
		if(f){
			temp1+=black;
			temp2+=white;
		}
		else 
		{
			temp1+=white;
			temp2+=black;
		}
		f = 1 - f;
	}
	int counter = 0;
	f = 1;
	forn(i,r*a)
	{
		if(f) cout<<temp1<<endl;
		else cout<<temp2<<endl;
		counter++;
		if(counter%a==0) f = 1 - f;
	}
	return 0;
}
