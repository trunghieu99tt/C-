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

/* Extend Euclid: ax + by = c;
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/
/*--------------------------------------------------------------------------------------------------*/

vector<vector<char>> board (4, vector<char>(4));

int ans = INT_MAX;

int a[3][3];

void trunghieu()
{
    int i,j;
    vi sumRow, sumCol;
    int sumD1 = 0, sumD2 = 0;
    forn(i,3)
    {
        int tmp = 0;
        forn(j,3)
        {
            cin>>a[i][j];
            if(i == j)
                sumD1+=a[i][j];
            if(i == 3 - j - 1)
                sumD2+=a[i][j];
            tmp+= a[i][j];
        }
        sumRow.pb(tmp);
    }
    forn(j,3)
    {
        int tmp = 0;
        forn(i,3)
            tmp+=a[i][j];
        sumCol.pb(tmp);
    }
    int k = ( sumD2 - sumRow[2] + sumRow[0])/2;
        i = sumRow[2] - sumRow[0] + k;
        j = sumCol[2] - sumCol[1] + k;
    cout<<i<<" "<<a[0][1]<<" "<<a[0][2]<<endl;
    cout<<a[1][0]<<" "<<j<<" "<<a[1][2]<<endl;
    cout<<a[2][0]<<" "<<a[2][1]<<" "<<k<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    trunghieu();
    return 0;
}