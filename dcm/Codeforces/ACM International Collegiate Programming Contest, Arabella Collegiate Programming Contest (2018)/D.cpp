#include<bits/stdc++.h>

using namespace std;

/*-----------------------------------GENERAL USER DEFINATION ------------------------------*/
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
        int n, x,  y;
        cin>>n>>x>>y;
        int numBlack, numWhite;
        if(n%2 == 0)
            numBlack = n/2, numWhite = n/2;
        else numBlack = n/2 + 1, numWhite = n/2;
        if(x >= numBlack && y>= numWhite)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}