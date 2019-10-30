#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

string toStr(int n)
{
	string ans;
	ostringstream converter;
	converter<<n;
	ans = converter.str();
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,k;
    cin>>t;
    forn(k,t)
    {
    	int n;
    	cin>>n;
    	int a[n],i,j;
    	map<int,vi> group;
    	map<int,int> counter,firstGo, visited;
    	forn(i,n)
    	{
    		cin>>a[i];
    		counter[a[i]]++;
    		if(visited[a[i]] ==0)
    		{
    			firstGo[a[i]] = i;
    			visited[a[i]] = 1;
    		}
    	}
    	sort(a,a+n);
    	i = 0;
    	vs ans;
    	string temp = "";
    	vi presenter, countSpace;
    	while(i < n)
    	{
    		while(a[i] == a[i+1])
    			temp+=toStr(a[i]) + " ",
    			i++;
    		if(i < n)
    			temp+=toStr(a[i]) + " ";
    		presenter.pb(a[i-1]);
    		ans.pb(temp);
    		countSpace.pb(count(all(temp),' '));
    		temp = "";
    		i++;
    	}
    	n = ans.size();
    	forn(i,n)
    	{
    		for(j = i+1;j<n;j++)
    		{
    			//cout<<presenter[i]<<" "<<presenter[j]<<" "<<firstGo[presenter[i]]<<" "<<firstGo[presenter[j]]<<endl;
    			if(countSpace[i] < countSpace[j] || countSpace[i] == countSpace[j] &&firstGo[presenter[i]] > firstGo[presenter[j]])
    			{
    				swap(ans[i],ans[j]);
    				swap(countSpace[i],countSpace[j]);
    			}
    		}
    	}
    	forn(i,n)
    		cout<<ans[i];
    	cout<<endl;
    }
    return 0;
}