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
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef double ld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	string s;
	cin>>s;
	string compare1="",compare2="";
	int i,j,f = 1;
	forn(i,n)
	{
		if(f)
		{
			compare1+='r';
			compare2+='b';
		}
		else 
		{
			compare1+='b';
			compare2+='r';
		}
		f = 1 - f;
	}
	int countRedCompare1=0,countBlueCompare1=0, countRedCompare2=0, countBlueCompare2=0;
	forn(i,n)
	{
		if(compare1[i]!=s[i])
		{
			if(compare1[i]=='r') countRedCompare1++;
			else countBlueCompare1++;
		}
		if(compare2[i]!=s[i])
		{
			if(compare2[i]=='r') countRedCompare2++;
			else countBlueCompare2++;
		}
	}
	int res1=0,res2=0;
	while(countRedCompare1>0 && countBlueCompare1>0)
	{
		res1++;
		countRedCompare1--;
		countBlueCompare1--;
	}
	if(countRedCompare1>0) res1+=countRedCompare1;
	else if(countBlueCompare1>0) res1+=countBlueCompare1;
	
	while(countRedCompare2>0 && countBlueCompare2>0)
	{
		res2++;
		countRedCompare2--;
		countBlueCompare2--;
	}
	if(countRedCompare2>0) res2+=countRedCompare2;
	else if(countBlueCompare2>0) res2+=countBlueCompare2;
	cout<<min(res1,res2);
	return 0;
}
