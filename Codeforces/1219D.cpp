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
    int n, k;
    cin>>n>>k;
    int a[n],i,j, c[n];
    int maxV = 0;
    forn(i,n)
    {
        cin>>a[i];
        maxV = max(maxV, a[i]);
    }
    int g;
    cin>>g;
    forn(i,n)
        cin>>c[i];
    ll ans = 0;
    priority_queue<int, vector<int> ,greater<int>> q;
    forn(i,n){
        q.push(c[i]);
        if(k < a[i]){

            while(!q.empty() && k < a[i]){
                k+=g;
                ans+= q.top();
                q.pop();
            }
            if(k < a[i])
            {
                cout<<-1;
                return;
            }
        }
    }
    cout<<ans;
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