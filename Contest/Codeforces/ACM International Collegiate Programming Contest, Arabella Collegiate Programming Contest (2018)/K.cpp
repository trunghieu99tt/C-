#include<bits/stdc++.h>

using namespace std;

/*-----------------------------------GENERAL USER's DEFINITION ------------------------------*/
#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

/*---------------------------------------------------------------------------------------*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        string a, b;
        cin>>a>>b;
        vector<char> characters;
        vi index;
        int i,j;
        forn(i,a.size())
        {
            if(a[i]!=b[i])
            {
                characters.pb(b[i]);
                index.pb(i);
            }
        }
        int n = index.size();
        string tmp = b;
        for(i = n-1;i>=0;i--)
        {
            if(i == n-1)
                tmp[index[0]] = characters[i];
            else tmp[index[i+1]] = characters[i];
        }
        if(tmp == a)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}