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
    int a[n][n],i,j;
    forn(i,n)
    	forn(j,n)
    		cin>>a[i][j];
    vi b;
    forn(i,n)
    	b.pb(i);
    vector<vi> ans;
    do{
    	int temp = 0;
    	forn(i,n)
    		temp+=a[i][b[i]];
    	if(temp == k)
    		ans.pb(b);
    }
    while(next_permutation(all(b)));
    cout<<ans.size()<<endl;
    for(i = 0;i<ans.size();i++)
    {
    	for(j = 0;j<ans[i].size();j++)
    		cout<<ans[i][j]+1<<" ";
    	cout<<endl;
    }
    return 0;
}