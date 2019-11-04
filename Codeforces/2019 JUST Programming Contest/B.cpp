#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
#define whatIs(a) cout<<#a<<" is : "<<a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;
clock_t t1,t2;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

ll inverserEuler(int n){return binPow(n, mod-2);}

ll C(int k, int n){vll f(n+1,1);for(int i = 2;i<=n;i++)f[i] = (f[i-1]*i)%mod;return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n-k]))%mod)%mod)%mod;}

/* Extend Euclid: ax + by = c;
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/
/*--------------------------------------------------------------------------------------------------*/

const int maxn = 1e5;

int n, m, q;

vector<pair<int,int>> filled(maxn), ok;

typedef pair<int,int> pii;

void trunghieu()
{
    int t;
    cin>>t;
    while(t--)
    {
    	cin>>n>>m>>q;
    	int i,j;
    	forn(i,n)
    	{
    		int l, r;
    		cin>>l>>r;
    		filled[i] = {l,r};
    	}
    	sort(filled.begin(), filled.begin() + n);
    	map<int,vector<pii>> can;
    	map<int,int> countCan;
    	vi allPos;
    	forn(i,n-1)
    	{
    		if(filled[i+1].first - filled[i].second - 1 > 0)
    		{
    			int num = filled[i+1].first - filled[i].second - 1;
    			countCan[num]++;
    			can[num].eb(make_pair(filled[i].second + 1, filled[i+1].first - 1));
    			// cout<<filled[i].first<<" "<<filled[i].second<<" "<<filled[i + 1].first<<" "<<filled[i+1].second<<endl;
    			// cout<<num<<" "<<filled[i].second + 1<<" "<<filled[i+1].first - 1<<endl;
    			allPos.eb(num);
    		}
    	}
    	if(filled[n-1].second < m)
    	{
    		int num = m - filled[n-1].second;
    		countCan[num]++;
    		can[num].eb(make_pair(filled[n-1].second + 1, m));
    	}
    	// for(auto i:can)
    	// {
    	// 	cout<<i.first<<" : ";
    	// 	for(auto j:i.second)
    	// 		cout<<"("<<j.first<<","<<j.second<<") ";
    	// 	cout<<endl;
    	// }
    	// for(auto i:countCan)
    	// 	cout<<i.first<<" : "<<i.second<<endl;
    	map<int,int> idCan;
    	for(auto i:can)
    	{
    		idCan[i.first] = 0;
    		sort(all(i.second),[](pair<int,int> a, pair<int,int> b){
    			return a.second > b.second ||
    			a.second == b.second && a.first > b.first;
    		});
    	}
    	sort(all(allPos));
    	forn(i,q)
    	{
    		int k;
    		cin>>k;
    		int id = lower_bound(all(allPos),k) - allPos.begin();
    		//cout<<"Now: "<<k<<" "<<allPos[id]<<" "<<countCan[allPos[id]]<<endl;
    		while(id < allPos.size() && countCan[allPos[id]] <= 0)
    			id++;
    		// whatIs(id);
    		// whatIs(allPos[id]);
    		if(id < allPos.size())
    		{
    			int x = allPos[id];
    			pair<int,int> tmpAns = can[x][idCan[x]++];
    			cout<<tmpAns.first<<" "<<tmpAns.second<<endl;
    			countCan[x]--;
    		}
    		else cout<<"-1 -1\n";
    	}
    }
}

int main()
{
    cerr << "Program is running" << endl;
    t1 = clock();
    ios::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    trunghieu();
    t2 = clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cerr << "\nRunning in " << seconds << " seconds" << endl;
    return 0;
}