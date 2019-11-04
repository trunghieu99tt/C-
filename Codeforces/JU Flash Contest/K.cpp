#include<bits/stdc++.h>

using namespace std;

/*-----------------------------------GENERAL USER's DEFINITION ------------------------------*/
#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

/*---------------------------------------------------------------------------------------*/

const int maxn = 1e7 + 1;

int sum(int n, int k ,int a[])
{

}

bool snt[maxn];

void sangnt()
{
	int i,j;
	for(i = 1;i<=maxn;i++)
		snt[i] = 1;
	snt[1] = 0;
	i = 2;
	while(i*i<=maxn)
	{
		while(snt[i] == 0)
			i++;
		for(j = 2;j*i<=maxn;j++)
			snt[i*j] = 0;
		i++;
	}
}

int check(int a[], int n)
{
	int i,j;
	map<ll,int> sum;
	do{
		ll temp = 0;
		for(j = 0;j<n;j++)
		{
			temp+= a[j];
			sum[temp]++;
		}
	}
	while(next_permutation(a,a+n));
	return sum.size();
}

ll giaithua(int n)
{
	if(n ==0 || n == 1)
		return 1;
	return n * giaithua(n-1);
}

ll C(int n, int k)
{
	return giaithua(n)/(giaithua(k) * giaithua(n-k));
}

ll counter(int n)
{
	ll ans = 0;
	for(int i = 1;i<=n;i++)
		ans+= C(n,i);
	return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    if(n == 1)
    {
    	cout<<1;
    	return 0;
    }
    if(n == 2)
    {
    	cout<<"1 2";
    	return 0;
    }
    if(n == 3)
    {
    	cout<<"1 10 10000";
    	return 0;
    }
    sangnt();
    int i1 = 3, i2 = 1e7, j, cnt = 1, ans[n];
    ll lim = 1;
	j = 0;
	while(j < n)
	{
	   	// while(snt[i1] == 0)
	    // 	i1++;
	    while(snt[i2] == 0)
	    	i2--;
	    if(cnt == lim)
	    {
	    	ans[j++] = i2;
	    	lim*=2;
	    }
	    else cnt++;
	    i2--;
	}
	forn(j,n)
	    cout<<ans[j]<<" ";
	//cout<<counter(n)<<" "<<check(ans,n)<<endl;
    return 0;
}