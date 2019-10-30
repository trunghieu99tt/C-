#include <bits/stdc++.h>
 
#define forn(i, n) for (li i = 0; i < li(n); i++)
#define ford(i, n) for (li i = li(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (li i = li(l); i < li(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) li((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<li, li> pt;
 
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
const li INF = li(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

li n, k;
 
void read() {
    cin>>n>>k;
}
 
const li mod = 1000 * 1000 * 1000 + 7;
 
li gcd(li a, li b, li& x, li& y) {
    if (!a) {
        x = 0, y = 1;
        return b;
    }
    li xx, yy, g = gcd(b % a, a, xx, yy);
    x = yy - b / a * xx;
    y = xx;
    return g;
}
 
inline li normal(li n) {
    n %= mod;
    (n < 0) && (n += mod);
    return n;
}
 
inline li inv(li a) {
    li x, y;
    assert(gcd(a, mod, x, y) == 1);
    return normal(x);
}
 
inline li add(li a, li b) { return a + b >= mod ? a + b - mod : a + b; }
inline li sub(li a, li b) { return a - b < 0 ? a - b + mod : a - b; }
inline li mul(li a, li b) { return li(a * 1ll * b % mod); }
inline li _div(li a, li b) { return mul(a, inv(b)); }
 
inline li binPow(li a, li b) {
    li ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}
 
li calc(const vector<li>& y, li x) {
    li ans = 0;
    li k = 1;
    fore(j, 1, sz(y)) {
        k = mul(k, normal(x - j));
        k = _div(k, normal(0 - j));
    }
    forn(i, sz(y)) {
        ans = add(ans, mul(y[i], k));
        if (i + 1 >= sz(y)) break;
        k = mul(k, _div(normal(x - i), normal(x - (i + 1))));
        k = mul(k, _div(normal(i - (sz(y) - 1)), normal(i + 1)));
    }
    return ans;
}
 
inline li solve() {
    vector<li> y;
    li sum = 0;
    y.pb(sum);
    forn(i, k + 1) {
        sum = add(sum, binPow(i + 1, k));
        y.pb(sum);
    }
    if (n < sz(y)) return y[n];
    return calc(y, n);
}
 
int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
   
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    li t;
    cin>>t;
    while(t--)
    {
        read();
        cout<<solve()<<endl;
    }
   
    return 0;
}