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
    int n;
    cin>>n;
    int i,j,k, temp;
    vi a, b;
    forn(i,n)
    {
    	cin>>temp;
    	a.pb(temp);
    }
    b = a;
    sort(all(b));
    int step = 1;
    while(a!=b)
    {
    	for(i = 1;i<n;i++)
	    {
	    	for(j = n-1;j>=i;j--)
	    	{
	    		if(a[j] < a[j-1])
	    			swap(a[i],a[j-1]);
	    	}
	    }
	    cout<<"Buoc "<<step++<<": ";
    	forn(k,n)
    		cout<<a[k]<<" ";
    	cout<<endl;
    }
    return 0;
}