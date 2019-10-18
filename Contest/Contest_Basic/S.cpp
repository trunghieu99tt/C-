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
    forn(k,t)
    {
    	int n;
    	cin>>n;
    	int a[n], i, ans = -1, flag = 0;
    	map<int,int> counter;
    	forn(i,n)
    	{
    		cin>>a[i];
    		counter[a[i]]++;
    	}
    	forn(i,n)
    	{
    		if(counter[a[i]] > 1)
    		{
    			cout<<a[i]<<endl;
    			flag = 1;
    			break;
    		}
    	}
    	if(!flag)
    		cout<<"NO\n";
    }
    return 0;
}