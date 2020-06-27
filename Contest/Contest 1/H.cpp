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

int cnt = 0, n, k, s;
void solve(int x, int d, int sum)
{
	if(sum > s)
		return;
	if(d == 0)
	{
		if(sum == s)
			cnt++;
	}
	else
	{
		for(int i = x + 1 ;i<=n;i++)
			solve(i,d-1,sum+i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(1)
    {
    	cin>>n>>k>>s;
    	if(n == 0 && k == 0 && s == 0)
    		break;
    	cnt = 0;
    	solve(0,k,0);
    	cout<<cnt<<endl;
    }
    return 0;
}