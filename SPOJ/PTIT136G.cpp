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
	vector<string> temp;
	int r,c;
	cin>>r>>c;
	string t;
	int i;
	forn(i,r)
	{
		cin>>t;
		temp.pb(t);
	}
	auto mirr = temp;
	forn(i,c)
	{
		string t1="";
		for(auto j:mirr)
			t1+=j[i];	
		temp.pb(t1);
	}
	vector<string> res;
	for(auto i:temp)
	{
		string token;
		stringstream ss(i);
		while(getline(ss,token,'#'))
		{
			if(token.size()>=2)
				res.pb(token);
		}
	}
	sort(all(res));
	cout<<res[0];
}
