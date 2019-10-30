#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
clock_t t1, t2;

ll binPow(ll a, ll b) {ll x = 1, y = a; while (b) {if (b & 1)x = (x * y) % mod; y = (y * y) % mod; b >>= 1;} return x % mod;}

ll inverserEuler(int n) {return binPow(n, mod - 2);}

ll C(int k, int n) {vll f(n + 1, 1); for (int i = 2; i <= n; i++)f[i] = (f[i - 1] * i) % mod; return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n - k])) % mod) % mod) % mod;}

/* Extend Euclid: ax + by = c;
ll x, y;

void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/
/*--------------------------------------------------------------------------------------------------*/

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

const int maxn = 2e5 + 5;

int n, a[maxn];

map<ll, ll> cnt;

vector<unsigned long long> preCalc;

void pre() {
    unsigned long long ans = 1;
    for (int i = 1; i <= 64; i++)
        preCalc.eb(ans), ans *= 2;
}

ll checkPow(ll a, ll b) {
    int cnt = 0;
    while (b < a)
        b *= 2, cnt++;
    return (a == b) ? cnt : -1;
}

void solve()
{
    pre();
    cin >> n;
    int i, j;
    forn(i, n)
    cin >> a[i];
    int minV = *min_element(a, a + n);
    forn(i, n)
    {
        int x = checkPow(a[i], minV);
        if (x == -1)
        {
            cout << -1;
            return;
        }
        else cnt[x]++;
    }
    unsigned long long ans = 0;
    set<ll> v;
    for(auto i:cnt)
        v.insert(i.first);
    for (auto i : cnt) {
        if (v.size() == 1)
            break;
        int x = i.second;
        if (x % 2 != 0)
            ans++;
        cnt[i.first + 1] += (x / 2 + x % 2);
        v.insert(i.first + 1);
        v.erase(i.first);
    }
    ll finalValue = *v.begin();
    ll id = lower_bound(begin(preCalc), end(preCalc), cnt[finalValue]) - begin(preCalc);
    unsigned long long add = preCalc[id] - cnt[finalValue];
    ans += add;
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    solve();
    return 0;
}