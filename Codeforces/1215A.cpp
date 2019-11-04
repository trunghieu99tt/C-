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
 
 // Extend Euclid: ax + by = c;
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
 
/*--------------------------------------------------------------------------------------------------*/
 
 
 
void trunghieu()
{
    int a1, a2,k1,k2;
    cin>>a1>>a2>>k1>>k2;
    int n;
    cin>>n;
    int tmp = n;
    int x, ansMAx = 0;
    if(k1 > k2){
        x = min(a2, n/k2);
        ansMAx+= x;
        n-= x * k2;
        ansMAx += min(a1, n/k1);
    } else{
        x = min(a1, n/k1);
        ansMAx+= x;
        n-= x * k1;
        ansMAx += min(a2, n/k2);
    }
    for(int i = 0;i<a1;i++)
        tmp-= (k1 - 1);
    for(int i = 0;i<a2;i++)
        tmp-= (k2 - 1);
    cout<<max(0,min(tmp, ansMAx))<<" "<<max(0,max(tmp, ansMAx));
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