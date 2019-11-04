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
		int x;
		cin>>x;
		string dad,son;
		int Age;
		map<string,string> sonDad;
		map<string,int> ageGiveBirth;
		map<string,int> age;
		age.insert(mp("Ted",100));
		int i;
		forn(i,x)
		{
			cin>>dad>>son>>Age;
			sonDad.insert(mp(son,dad));
			ageGiveBirth.insert(mp(son,Age));
		}
		vector<vector<string>> tree{{"Ted"}};
		forn(i,x)
		{
			vector<string> temp;
			for(auto l:tree.back())
			{
				for(auto i:sonDad)
				{
					if(i.second == l)
					{
			
						int k = age[l]-ageGiveBirth[i.first];
						age.insert(mp(i.first,k));
						temp.pb(i.first);
					}
				}
			}
			tree.pb(temp);
		}
		cout<<"DATASET "<<k+1<<endl;
		multimap<int,string> res;
		for(auto i:age)
			res.insert(mp(i.second,i.first));
		vector<string> resName;
		vi resAge;
		for(auto i:res)
		{
			resName.pb(i.second);
			resAge.pb(i.first);
		}
		for(i=0;i<resName.size()-1;i++)
		{
			for(int j=i+1;j<resName.size();j++)
			{
				if(resAge[i]==resAge[j] && resName[i]>resName[j] || resAge[i]<resAge[j])
					{
						swap(resName[i],resName[j]);
						swap(resAge[i],resAge[j]);
					}
			}
		}
		for1(i,resName.size()-1)
			cout<<resName[i]<<" "<<resAge[i]<<endl;
		
	}
}
