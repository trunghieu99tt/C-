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

set<ll> ans;

void pre()
{
	for(int i = 1;i<=18;i++)
	{
		for(int j = 0;j<=i;j++)
		{
			string s = string(j,'0') + string(i - j, '9');
			do{
				ans.insert(atoll(s.c_str()));
			}
			while(next_permutation(all(s)));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,k;
    cin>>t;
    pre();
    while(t--)
    {
    	int n;
    	cin>>n;
    	set<ll>::iterator it;
    	for(it = ans.begin(); it!=ans.end();it++)
    	{
    		if(*it % n == 0 && *it >=n)
    		{
    			cout<<*it<<endl;
    			break;
    		}
    	}
    }
    return 0;
}