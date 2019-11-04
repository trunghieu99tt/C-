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
    int n,k;
    cin>>n>>k;
    int i,j, ans = INT_MIN,index;
    vi a;
    forn(i,n)
    {
    	int tmp;
    	cin>>tmp;
    	a.pb(tmp);
    }
    forn(i,n)
    {
    	vi b = a;
    	forn(j,n)
    	{
    		if((j-i)%k == 0)
    			b[j] = 0;
    	}
    	ans = max(ans, (int)abs(count(all(b),1) - count(all(b),-1)));
    }
    cout<<ans;
    return 0;
}