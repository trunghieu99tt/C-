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

ll solve(ll x , ll y)
{
	// f(0,0) = 0
	if(x == 0 && y == 0) 
		return 0;
	// f(3x, 2y) = f(x,y)
	else if(x%3 == 0 && y%2 == 0)
		return solve(x/3, y/2);
	// f(3x + 1, 2y) = f(x,y) + 1
	else if((x-1)%3 == 0 && y%2 == 0)	
		return solve((x-1)/3, y/2) + 1;
	// f(3x + 2, 2y) = f(x,y)
	else if((x-2)%3 == 0 && y%2 == 0)
		return solve((x-2)/3, y/2);
	// f(3x, 2y + 1) = f(x,y) + 1
	else if(x%3 == 0 && (y - 1)%2 == 0)
		return solve(x/3, (y-1)/2) + 1;
	// f(3x + 1, 2y + 1) = f(x,y) + 2;
	else if((x-1)%3 == 0 && (y-1)%2 == 0)
		return solve((x-1)/3, (y-1)/2) + 2;
	// f(3x+2, 2y + 1) = f(x,y) + 1;
	else if((x-2)%3==0 && (y-1)%2 == 0)
		return solve((x - 2)/ 3, (y-1)/2) + 1;
	
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
    	ll x, y;
    	cin>>x>>y;
    	cout<<solve(x,y)<<endl;
    }
    return 0;
}