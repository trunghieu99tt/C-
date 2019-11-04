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
    int x1, x2, x3, x4,h;
    cin>>x1>>x2>>x3>>x4>>h;
    if(x1 == x3 && x2 == x4)
    	cout<<ll(x2 - x1) * h;
    else if(x2 < x3 || x4 < x1)
    	cout<<0;
    else if(x1 <= x3 && x3 <= x2 && x2 <= x4)
    	cout<<ll(x2 - x3) * h;
    else if(x3 <= x1 && x1 <= x4 && x4 <= x2)
    	cout<<ll(x4 - x1) * h;
    else if(x1 <= x3 && x4 <= x2)
    	cout<<ll(x4 - x3) * h;
    else if(x3 <= x1 && x2 <= x4)
    	cout<<ll(x2 - x1) * h;
    return 0;
}