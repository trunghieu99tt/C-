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

void trunghieu()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n,m;
    	cin>>n>>m;
    	int i,j, sumH = 0, sumM = 0;
    	forn(i,n)
    	{
    		int h1, m1, h2, m2;
    		char c1, c2;
    		cin>>h1>>c1>>m1>>h2>>c2>>m2;
    		int tmpH = h2 - h1, tmpM = m2 - m1;
    		// cout<<"tmpM: "<<tmpM<<" tmpH : "<<tmpH<<endl;
    		// cout<<"before: \n";
    		//whatIs(tmpH);whatIs(tmpM);
    		if(tmpM < 0)
    		{
    			tmpH--;
    			tmpM+=60;
    		}
    		// cout<<"after: \n";
    		// whatIs(tmpH);whatIs(tmpM);
    		sumH+=tmpH + tmpM/60;
    		sumM+= tmpM%60;
    	}
    	//whatIs(sumH);whatIs(sumM);
    	sumH+= sumM/60;
    	sumM%=60;
    	//whatIs(sumH);whatIs(sumM);
    	if(sumH >= m)
    		cout<<"YES\n";
    	else cout<<"NO\n";
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