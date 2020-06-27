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
    vi a;
    forn(i,n)
    {
    	cin>>temp;
    	a.pb(temp);
    }
    i = 0;
    vi b;
    int step = 0;
    while(i<n)
    {
    	if(b.empty())
    		b.push_back(a[i]);
    	else
    		b.insert(lower_bound(all(b),a[i]),a[i]);
    	cout<<"Buoc "<<step++<<": ";
    	for(j = 0;j<b.size();j++)
    		cout<<b[j]<<" ";
    	i++;
    	cout<<endl;
    }
    return 0;
}