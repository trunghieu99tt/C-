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
	int t,k;
	cin>>t;
	forn(k,t)
	{
		int n;
		cin>>n;
		vector<string> dna;
		set<string> check;
		string temp;
		int i;
		forn(i,n)
		{
			cin.ignore();
			cin>>temp;
			dna.pb(temp);
			check.insert(temp);
		}
		if(check.size()==1) cout<<dna[0]<<endl;
		else
		{
				int maxL=3,j;
			bool check = 0;
			vector<string> r, res;
			for(i=0;i<60;i++)
			{
				for(j=i;j<60;j++)
				{
					string t = dna[0].substr(i,j-i);
					bool flag=1;
					for(auto k:dna)
					{
						if(k.find(t)==string::npos)
						{
							flag=0;
							break;
						}
					}
					if(flag)
					{
						if(j-i>=maxL)
						{
							check = 1;
							r.pb(t);
							maxL = j-i;
						}
					}
				}
			}
			if(check==0) cout<<"no significant commonalities"<<endl;
			else
			{
				int maxlen = 0;
				for(auto i:r)
					if(i.size()> maxlen) maxlen = i.size();
				for(auto i:r)
					if(i.size()==maxlen) res.pb(i);
				sort(all(res));
				cout<<res[0]<<endl;
			}
		}
	}
}
