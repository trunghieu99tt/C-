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
    long n;
    cin >> n;
    long long k,x;
    cin >> k >> x;
    long long P[n];
    long long F[n];
    for(long i=0;i<n;i++)
    {
    	cin << P[i];
    }
    sort(P,P+n);
    F[0]=1;
    long j=1;
    for(long i=1;i<n;i++)
    {
    	if(P[i]<P[0]*((j-1)*x)) F[i]=1;
    	j++;
    }

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    return 0;
}
