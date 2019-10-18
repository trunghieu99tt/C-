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
    	int n, m, k, i,j,cnt = 0,wrongTest;
    	cin>>n>>m>>k;
    	char sizeOfTest[k], verdict;
    	int failed[n];
    	forn(i,n)
    		cin>>sizeOfTest[i];
    	memset(failed,0,sizeof(failed));
    	forn(i,m)
    	{
    		cin>>verdict;
    		if(verdict == 'W')
    		{
    			cin>>wrongTest;
    			if(failed[wrongTest] == 0 && sizeOfTest[wrongTest - 1] == 'S')
    				cnt++, failed[wrongTest] = 1;
    		}
    	}
    	cout<<cnt<<endl;
    }
    return 0;
}