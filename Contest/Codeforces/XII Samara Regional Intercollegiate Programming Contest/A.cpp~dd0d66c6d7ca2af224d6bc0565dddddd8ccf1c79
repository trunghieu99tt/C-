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
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
#define whatIs(a) cout<<#a<<" is : "<<a<<endl
 
 
/*--------------------------------- USER'S TYPEDEF -----------------------------------------*/
 
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int,int> pii;
 
clock_t t1, t2;
 
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
 
struct chash{
  int operator()(int x) const{return x^RANDOM;}
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
int dr[] = {-1, 0, 0 ,1};
int dc[] = {0, -1 , 1, 0};
vector<string> g;
int n, m;
int dist(pair<int,int> a, pair<int,int> b){
    map<pair<int,int>, int> ans;
    vector<vector<int>> visited(n, vector<int>(m, 0 ));
    ans[a] = 0;
    queue<pair<int,int>> q;
    q.push(a);
    visited[a.first][a.second] = 1;
    while(!q.empty()){
        auto u = q.front();q.pop();
        for(int k = 0; k<4;k++){
            int x = u.first + dr[k], y = u.second + dc[k];
            if(x >= 0 && y >= 0 && x < n && y < m){
                if(g[x][y] == '0' && !visited[x][y])
                {
                    ans[{x,y}] = ans[u] + 1;
                    q.push({x,y});
                    visited[x][y] = 1;
                }
                else if(x == b.first && y == b.second)
                    return ans[u];
                else if(g[x][y] == '1' && !visited[x][y]){
                    q.push({x,y});
                    visited[x][y] = 1;
                }
            }
        }
    }
    return INT_MAX;
}

void go(pair<int,int> a, pair<int,int> b){
    map<pair<int,int>, int> ans;
    vector<vector<int>> visited(n, vector<int>(m, 0 ));
    queue<pair<int,int>> q;
    map<pair<int,int> , pair<int,int>> parent;
    q.push(a);
    visited[a.first][a.second] = 1;
    int flag = 0;
    while(!q.empty() && !flag){
        auto u = q.front();q.pop();
        for(int k = 0; k<4;k++){
            int x = u.first + dr[k], y = u.second + dc[k];
            if(x >= 0 && y >= 0 && x < n && y < m){
                if(g[x][y] == '0' && !visited[x][y])
                {
                    q.push({x,y});
                    visited[x][y] = 1;
                    parent[{x,y}] = u;
                }
                else if(x == b.first && y == b.second)
                {
                    parent[b] = u;
                    flag = 1;
                    break;
                }
            }
        }
    }
    while(b != a){
        g[b.first][b.second] = '1';
        b = parent[b];
    }
}

int bridgesCost(std::vector<std::string> a)
{
    vector<vector<pair<int,int>>> island;
    int i,j;
    g = a;
    n = a.size(), m = a[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0 ));
    for(i = 0;i<n;i++){
        for(j = 0;j<m;j++){
            if(a[i][j] == '1' && !visited[i][j]){
                vector<pair<int,int>> tmp;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = 1;
                while(!q.empty()){
                    auto u = q.front();q.pop();
                    tmp.emplace_back(u);
                    for(int k = 0;k<4;k++){
                        int x = u.first + dr[k],
                            y = u.second + dc[k];
                        if(x >= 0 && y >= 0 && x < n && y < m && a[x][y] == '1' && !visited[x][y]){
                            q.push({x,y});
                            visited[x][y] = 1;
                        }
                    }
                }
                island.emplace_back(tmp);
            }
        }
    }
    for(auto i:island){
    	for(auto j:i){
    		cout<<j.first<<" "<<j.second<<endl;
    	}
    	cout<<"========\n";
    }
    int ans = 0;
    for(int i = 0;i<island.size() - 1;i++){
        int t = INT_MAX;
        pair<int,int> mU, mV;
        for(auto u: island[i]){
            for(auto v:island[i + 1]){
                int d = dist(u,v);
                if(d < t){
                    t = d;
                    mU = u;
                    mV = v;
                }
            }
        }
        cout<<mU.first<<" "<<mU.second<<" "<<mV.first<<" "<<mV.second<<endl;
        go(mU, mV);
        ans+= t;
    }
    return ans;
}

 
void trunghieu()
{
	//cout<<travelPath("Bac Giang", "Ha Noi", {{"Bac Giang","Bac Ninh","9000"},{"Bac Giang","Ha Noi", "2000"}});
	//cout<<marble1(4,2);
	cout<<bridgesCost({"11000","11000","00100","00010","00111","00111"});
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