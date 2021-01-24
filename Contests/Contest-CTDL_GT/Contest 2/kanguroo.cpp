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
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n],i, ans = n;
    	forn(i,n)
    		cin>>a[i];
    	sort(a,a+n);
        int index = n/2;
    	for(i = 0;i<n/2;i++)
        {
            while(a[i] * 2 > a[index] && index < n)
                index++;
            if(index>=n)
                break;
            if(a[i] * 2 <= a[index])
            {
                ans--;
                index++;
            }
            if(index>= n)
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
