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
	string s;
	cin>>s;
	set<string> res;
	for(int i=97;i<=122;i++)
	{
		string t = "";
		t+=i;
		for(int j=0;j<=s.size();j++)
		{
			string temp = s;
			temp.insert(j,t);
			res.insert(temp);
		}
	}
	cout<<res.size();
	return 0;
}
