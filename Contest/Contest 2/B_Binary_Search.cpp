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

int binary_search(int a[], int k, int lo, int hi)
{
	while(lo <= hi)
	{
		int mid = (lo + hi)/2;
		if(a[mid] == k)
			return mid;
		if(k > a[mid])
			lo = mid + 1;
		else hi = mid - 1;
	}
	return -1;
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
    	int n, k;
    	cin>>n>>k;
    	int a[n],i;
    	forn(i,n)
    		cin>>a[i];
    	sort(a,a+n);
    	int index = binary_search(a, k, 0, n-1);
    	if(index!=-1)
    		cout<<index + 1<<endl;
    	else cout<<"NO\n";
    }
    return 0;
}