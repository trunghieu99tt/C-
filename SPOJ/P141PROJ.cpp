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
#define mp make_pair
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
	char test[4][4];
	int i,j;
	forn(i,4)
		forn(j,4)
			cin>>test[i][j];
	vector<string> check;
	forn(i,3)
	{
		forn(j,3)
		{
			string temp="";
			temp+=test[i][j];
			temp+=test[i+1][j];
			temp+=test[i][j+1];
			temp+=test[i+1][j+1];
			check.pb(temp);
		}
	}
	for(auto i:check)
	{
		int countDot=0,counter=0;
		for(auto j:i)
			if(j=='#') counter++;
		else countDot++;
		if(abs(counter-countDot)>=2)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}
