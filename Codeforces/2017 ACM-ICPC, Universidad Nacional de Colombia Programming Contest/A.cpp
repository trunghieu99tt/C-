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
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;

/*--------------------------------------------------------------------------------------------------*/

string maxAns="0";
string minAns ="999999999999999999";

int cmp(string a, string b){
    if(a.size()>b.size()) return 1;
    else if(a.size()< b.size()) return-1;
    else {
        for(int i=0; i<a.size(); ++i){
            if(a[i] < b[i]) return -1;
            else if(a[i] > b[i]) return 1;
        }
    }
    return 0;
}

string addString(string a, string b){
    while(a.size()!=b.size()){
        if(a.size() > b.size()) b = b+'0';
        else if(a.size() < b.size()) a= a+'0';
    }

    string ans="";
    int n= a.size();
    for(int i=0; i<n; ++i){
        ans = ans + char(((a[i]-'0')+(b[i]-'0'))%10+'0');
    }
    reverse(ans.begin(), ans.end());
    while(ans[0]=='0'&& ans.size()>1){
       ans=&ans[1];
    }
    return ans;
}

void solve(vs a, int n){
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j){
            string temp= addString(a[i], a[j]);
            if(cmp(maxAns, temp)==-1) maxAns=temp;
            if(cmp(minAns, temp)==1 ) minAns= temp;
        }
    }
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
    vs a(1000001);
    for(int i=0; i<n; ++i){
        cin>>a[i];
        reverse(a[i].begin(), a[i].end());
    }
    solve(a, n);
    cout<<minAns<<" "<<maxAns;
    return 0;
}