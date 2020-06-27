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

int ok;

void next_per(int x[], int n, int k)
{
	int i = k - 1,j;
	while(i >=0 && x[i] == n - k + i + 1 && i>=0)
		i--;
	x[i] = x[i]+1;
	for(j = i+1;j<k;j++)
		x[j] = x[j-1] + 1;
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
		int n,k;
		cin>>n>>k;
		int a[k],i, flag = 0;
		map<int,int> exist;
		forn(i,k)
		{
			cin>>a[i];
			exist[a[i]] = 1;
		}
		forn(i,n)
		{
			if(a[i]!= n - k + i + 1)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			cout<<k<<endl;
		else
		{
			next_per(a, n , k);
			int ans = 0;
			forn(i,k)
			{
				if(exist[a[i]] == 0)
					ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}