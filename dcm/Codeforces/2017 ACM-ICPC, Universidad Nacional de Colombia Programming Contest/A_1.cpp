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

string add(string a, string b)
{
    int n = max(int(a.size()), int(b.size())), i,j;
    string ans = "";
    while(a.size()!=n)
        a = '0' + a;
    while(b.size()!=n)
        b = '0' + b;
    forn(i,n)
        ans+= (((a[i] - '0') + (b[i] - '0'))%10 + '0');
    if(count(all(ans),'0') == ans.size())
        return "0";
    if(ans[0] == '0')
        ans = ans.substr(ans.find_first_not_of('0'));
    return ans;
}

bool cmp(string a, string b)
{
    if(a.size() < b.size())
        return 0;
    if(a.size() > b.size())
        return 1;
    return a > b;
}

const int maxn = 1e6;

int n;
string num[maxn];

void trunghieu()
{
    cin>>n;
    int i,j;
    forn(i,n)
        cin>>num[i];
    string maxAns = string(1,'0'), minAns = string(18,'9');
    for(i = 0;i<n-1;i++)
    {
        for(j = i+1;j<n;j++)
        {
            string tmpAdd = add(num[i],num[j]);
            //cout<<num[i]<<" "<<num[j]<<" "<<tmpAdd<<endl;
            if(!cmp(tmpAdd,minAns))
            {
                //cout<<num[i]<<" "<<num[j]<<" "<<mpAdd<<" "<<minAns<<endl;
                minAns=  tmpAdd;
            }
            if(cmp(tmpAdd,maxAns))
                maxAns = tmpAdd;
        }
    }
    cout<<minAns<<" "<<maxAns;
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