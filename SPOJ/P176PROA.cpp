#include<bits/stdc++.h>
 
#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define fore(i,l,r) for(i=l;i<=r;++i)
#define ford(i,n) for(i=n-1;i>=0;--i)
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

vector<string> generate(vector<string> x, int length)
{
	if(length==0) return {};
	int counter=1;
	vector<string> res;
	for(auto i:x)
		res.pb(i);
	while(counter < length)
	{
		vector<string> temp;
		for(auto i:res)
		{
			for(auto j:x)
				{
					string t = i;
					t+=j;
					temp.pb(t);
				}
		}
		res = temp;
		counter++;
	}
	return res;
}
 

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	string a[n];
	int i,j;
	vector<string> x{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	forn(i,n)
		cin>>a[i];
	for(i=1;i<=20;i++)
	{
		vector<string> temp = generate(x,i);
		for(auto j:temp)
		{
			bool flag = 1;
			for(auto k:a)
				if(k.find(j)!=string::npos)
				{
					flag = 0;
					break;
				}
			if(flag == 1)
			{
				cout<<j;
				return 0;
			}
		}
	}
	return 0;
}
 
