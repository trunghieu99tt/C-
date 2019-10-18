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
    int t,k;
    cin>>t;
    forn(k,t)
    {
    	int n,m,p;
    	cin>>n>>m>>p;
    	int a[n],b[m],i,j;
    	forn(i,n)
    		cin>>a[i];
    	forn(i,m)
    		cin>>b[i];
    	cout<<"Test "<<k+1<<":\n";
    	forn(i,p)
    		cout<<a[i]<<" ";
    	forn(i,m)
    		cout<<b[i]<<" ";
    	for(i = p;i<n;i++)
    		cout<<a[i]<<" ";
    	cout<<endl;
    }
    return 0;
}