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
//	freopen("input.txt","r",stdin);
	string s;
	cin>>s;
	vector<string> split,res;
    s="0"+s+"0";
	while(s.size())
	{
        if(s.substr(0,s.find('*'))!="")
		    split.pb(s.substr(0,s.find('*')));
		s.erase(0,s.find('*')+1);
		if(s.find('*')==string::npos) {
			if(s.size()) split.pb(s);
			break;
		}
	}
	int n;
	cin>>n;
	string options[n];
	int i;
	forn(i,n)
		cin>>options[i];
	for(auto i:options)
	{
        string temp="0"+i+"0";
		int k,flag=1;
        for(auto j:split)
        {
            k=temp.find(j);
            if(k==string::npos || j.size() > temp.size())
            {
                flag=0;
                break;
            }
            temp = temp.substr(j.size());
        }
        if(flag) res.pb(i);
	}
	for(auto i:res)
		cout<<i<<endl;
	return 0;
}
