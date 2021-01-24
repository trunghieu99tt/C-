#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

ll inverserEuler(int n){return binPow(n, mod-2);}

ll C(int k, int n){vll f(n+1,1);for(int i = 2;i<=n;i++)f[i] = (f[i-1]*i)%mod;return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n-k]))%mod)%mod)%mod;}

/* Extend Euclid: ax + by = c; */
//ll x, y;
 
//void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;

/*--------------------------------------------------------------------------------------------------*/

vi a(6), b(6);

void trunghieu()
{
    int i,j;
    forn(i,6)
        cin>>a[i];
    forn(i,6)
        cin>>b[i];
    queue<vi> q;
    q.push(a);
    map<vi,int> ans, visited;
    ans[a] = 0;
    while(!q.empty())
    {
        vi u = q.front();
        if(u == b)
        {
            cout<<ans[u];
            return;
        }
        q.pop();
        vi tmpA = u, tmpB = u;
        tmpA[1] = u[4]; tmpA[2] = u[1];tmpA[4] = u[5];tmpA[5] = u[2];
        tmpB[0] = u[3]; tmpB[1] = u[0];tmpB[3] = u[4];tmpB[4] = u[1];
        if(visited[tmpA] == 0)
        {
            visited[tmpA] = 1;
            q.push(tmpA);
            ans[tmpA] = ans[u] + 1;
        }
        if(visited[tmpB] == 0)
        {
            visited[tmpB] = 1;
            q.push(tmpB);
            ans[tmpB] = ans[u] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     //freopen("output.txt","w",stdout);
    // #endif
    trunghieu();
    return 0;
}