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

ll solve(int n, ll k)
{
	ll index = round(pow(2,n-1));
	if(k == index)
		return n;
	if(k > index)
		return solve(n-1, k - index);
	return solve(n-1, k);
}


int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	ll k;
    	cin>>n>>k;
    	cout<<solve(n,k)<<endl;
    }
    return 0;
}