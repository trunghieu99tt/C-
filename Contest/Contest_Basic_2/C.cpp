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
    int t,l;
    cin>>t;
    forn(l,t)
    {
    	int n;
    	cin>>n;
    	int a[n][n] = {{0}},b[n][n] = {{0}},i,j,k;
    	forn(i,n)
    	{
    		int begin = 1;
    		forn(j,n)
    		{
    			a[i][j] = 0;
    			if(j<=i)
    				a[i][j] = begin++;
    			b[j][i] = a[i][j];
    		}
    	}
    	int ans[n][n];
    	forn(i,n)
    	{
    		forn(j,n)
    		{
    			ans[i][j] = 0;
    			forn(k,n)
    				ans[i][j]+= a[i][k] * b[k][j];
    		}
    	}
    	cout<<"Test "<<l+1<<":\n";
    	forn(i,n)
    	{
    		forn(j,n)
    			cout<<ans[i][j]<<" ";
    		cout<<endl;
    	}
    }
    return 0;
}