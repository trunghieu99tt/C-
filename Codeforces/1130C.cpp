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
// ll x, y;

// void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;

/*--------------------------------------------------------------------------------------------------*/

const int maxn = 100;
char a[maxn][maxn];
int visited[maxn][maxn];

int cost(int x1, int y1, int x2, int y2)
{
    return round(pow(x2-x1,2)) + round(pow(y2-y1,2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int r1, c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    int i,j;
    fill2D(visited,n + 1,n + 1,0);
    forn(i,n)
        forn(j,n)
            cin>>a[i][j];
    int dr[] = {-1,0,0,1},
        dc[] = {0,-1,1,0};
    vector<pair<int,int>> reachFromA, reachFromB;
    queue<pair<int,int>> q;
    q.push({r1,c1});
    while(!q.empty())
    {
        pair<int,int> u = q.front();
        reachFromA.pb({u.first, u.second});
        q.pop();
        forn(i,4)
        {
            int x = u.first + dr[i], y = u.second + dc[i];
            if(x>=1 && y>=1 && x <= n && y <= n && visited[x][y] == 0 && a[x-1][y-1] == '0')
            {
                visited[x][y] = 1;
                q.push({x,y});
            }
        }
    }
    q.push({r2,c2});
    while(!q.empty())
    {
        pair<int,int> u = q.front();
        reachFromB.pb({u.first, u.second});
        q.pop();
        forn(i,4)
        {
            int x = u.first + dr[i], y = u.second + dc[i];
            if(x>=1 && y>=1 && x <= n && y <= n && visited[x][y] == 0 && a[x-1][y-1] == '0')
            {
                visited[x][y] = 1;
                q.push({x,y});
            }
        }
    }
    int nA = reachFromA.size(), nB = reachFromB.size(), ans = INT_MAX;
    forn(i,nA)
    {
        forn(j,nB)
        {
            // cout<<ans<<" "<<cost(reachFromA[i].first, reachFromA[i].second, reachFromB[j].first, reachFromB[j].second)<<endl;
            // cout<<reachFromA[i].first<<" "<<reachFromA[i].second<<" "<<reachFromB[j].first<<" "<<reachFromB[j].second<<endl;
            ans = min(ans, cost(reachFromA[i].first, reachFromA[i].second, reachFromB[j].first, reachFromB[j].second));
        }
    }
    cout<<ans;
    return 0;
}
