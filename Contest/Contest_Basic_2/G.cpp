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

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,k;
    cin>>t;
    map<char,int> value;
    map<string,int> valueSub;
    value['I'] = 1;value['V'] = 5; value['X'] = 10;value['L'] = 50; value['C'] = 100, value['D'] = 500, value['M'] = 1000;
    forn(k,t)
    {
    	string s;
    	cin>>s;
    	int i = 0;
    	long long ans = 0;
    	while(i<s.size())
    	{
    		int value1 = value[s[i]];
    		if(i+1<s.size())
    		{
    			int value2 = value[s[i+1]];
    			if(value1 >= value2)
    				ans+=value1;
    			else
    			{
    				ans+= (value2 - value1);
    				i++;
    			}
    		}
    		else
    			ans+=value1;
    			i++;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}