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

string convert(int n)
{
	string res="";
	while(n)
	{
		res+=(n%3+'0');
		n/=3;
	}
	reverse(all(res));
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	int a,b;
	cin>>a>>b;
	string c1 = convert(a),c2 = convert(b);
	int n = max(c1.size(),c2.size());
	while(c1.size()!=n) c1 = "0"+c1;
	while(c2.size()!=n) c2 = "0"+c2;
	int i;
	string res="";
	forn(i,n)
	{
		int d1 = c1[i]-'0', d2 = c2[i]-'0',num;
		if(d2-d1>=0) num = d2-d1;
		else num = d2 - d1+3;
		res+=(num+ '0');
	}
	cout<<stoll(res,nullptr,3);
	return 0;
}
