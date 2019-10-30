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

const int maxn = 10, mod = 1e9 + 7;

typedef struct matrix{
	ll a[maxn][maxn];
} matrix;

matrix multi(matrix mtA, matrix mtB, int n)
{
	matrix ans;
	int i,j,k;
	forn(i,n)
		forn(j,n)
		{
			ans.a[i][j] = 0;
			forn(k,n)
				ans.a[i][j]+= (mtA.a[i][k] * mtB.a[k][j])%mod;
		}
	return ans;
}

matrix modulo(matrix mt , int n)
{
	matrix ans;
	int i,j;
	forn(i,n)
		forn(j,n)
			ans.a[i][j] = mt.a[i][j]%mod;
	return ans;
}


matrix matrixPow(matrix base, int k, int n)
{
	matrix ans;
	int i,j;
	forn(i,n)
		forn(j,n)
			ans.a[i][j] = (i == j);
	while(k)
	{
		if(k&1)
			ans = modulo(multi(ans,base,n), n);
		base = modulo(multi(base, base,n), n);
		k>>=1;
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    	int n, k;
    	cin>>n>>k;
    	matrix base;
    	int i,j;
    	forn(i,n)
    		forn(j,n)
    			cin>>base.a[i][j];
    	matrix ans = matrixPow(base, k, n);
    	forn(i,n)
    	{
    		forn(j,n)
    			cout<<ans.a[i][j]<<" ";
    		cout<<endl;
    	}
    return 0;
}