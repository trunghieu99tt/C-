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

bool check(string s)
{
	string s1 = s;
	sort(all(s1));
	return s == s1;
}


void trunghieu()
{
	ll dp[100][10], dpNum[100];
	for(int i = 1;i<=9;i++)
		dp[1][i] = 1,
		dp[0][i] = 0;
	dp[1][0] = 1;
	dp[0][0] = 0;
	dpNum[1] = 10;
	dpNum[0] = 0;
	for(int i = 2;i<=80;i++)
	{
		ll x = dpNum[i-1];
		dpNum[i] = x;
		dp[i][0] = 0;
		for(int j = 1;j<=9;j++)
		{
			dp[i][j] = x - dp[i-1][j-1];
			x-= dp[i-1][j-1];
			dpNum[i]+=dp[i][j];
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		if(!check(s))
			cout<<-1<<endl;
		else
		{
			int i,j, num = s.size();
			ll ans = 0;
			//ans+= dpNum[num-1];
			//cout<<ans<<endl;
			cout<<dpNum[num]<<endl;
			//ans+= dpNum[num-1] + dp[num][s[0] - '0' - 1];
			for(i = num;i>=1;i--)
			{
				//cout<<dpNum[i-1]<<endl;
				// ans+= dpNum[i-1];
				// for(j = 1;j<=s[0] - '0' - 1;j++)
				// 	ans+= dp[i-1][j];
				if(i > 1)
					ans+= (dpNum[i-1] + dp[i][s[0] - '0' - 1]);
				else ans+= (dpNum[i-1] + dp[i][s[0] - '0' - 2]);
				s = s.substr(1);
			}
			cout<<ans<<endl;
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