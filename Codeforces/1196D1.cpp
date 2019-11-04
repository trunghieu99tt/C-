#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>

using namespace __gnu_pbds;
using namespace std;

/*--------------------------------- USER'S DEFINE -----------------------------------------*/

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define whatIs(x) cerr << "Line "<<__LINE__ << ": " << #x << " = " << (x) << endl


/*--------------------------------- USER'S TYPEDEF -----------------------------------------*/

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;

/*---------------------------------POLICY-BASED-DATA STRUCTURES -------------------------------*/

// Set up chash for hash table

ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
ll SEED = ll(new ll);
ll RANDOM = TIME^SEED;
ll MOD = (int)1e9 + 7;
ll MUL = (int)1e6 + 3;

 
// optionn 1 (slower - don't know why)
//struct chash{
//  ll operator()(ll x) const {return std::hash<ll>{}((x^RANDOM)%MOD * MUL);}
//};
 
// Option 2
struct chash{
  int operator()(int x) const{return x^RANDOM;}
};

// Option 3 (fastest)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 

// Set up trie
typedef trie<string,null_type,trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> trie;

// Set up Red-Black Tree
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rb_tree;

/*-----------------------------------USEFUL FUNCS -----------------------------------------------*/

ll binPow(ll a, ll b) {ll x = 1, y = a; while (b) {if (b & 1)x = (x * y) % MOD; y = (y * y) % MOD; b >>= 1;} return x % MOD;}

ll inverserEuler(ll n) {return binPow(n, MOD - 2);}

ll C(ll k, ll n) {vll f(n + 1, 1); for (ll i = 2; i <= n; i++)f[i] = (f[i - 1] * i) % MOD; return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n - k])) % MOD) % MOD) % MOD;}

/* Extend Euclid: ax + by = c;
ll x, y;

void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/

/*--------------------------------- USER'S SOLVE FUNC -------------------------------------------*/

int calc(string s, string t){
    int i,n = s.size(), ans = 0;
    forn(i,n){
        ans+= s[i] != t[i];
    }
    return ans;
}

void trunghieu()
{
    string pattern = "RGB";
    while(pattern.size() < 2e4)
        pattern+=pattern;
    int q;
    cin>>q;
    while(q--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<string> p{pattern.substr(0,k),pattern.substr(1,k),pattern.substr(2,k)};
        int ans = INT_MAX;
        for(int i = 0;i<=s.size()-k;i++){
            string t = s.substr(i, k);
            for(auto j:p){
                ans = min(ans, calc(t,j));
            }
        }
        cout<<ans<<endl;
    }
}


/*--------------------------------- MAIN FUNC ---------------------------------------------------*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
#endif
    trunghieu();
    return 0;
}