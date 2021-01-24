#include<bits/stdc++.h>
 
#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define fore(i,l,r) for(i=l;i<=r;++i)
#define ford(i,n) for(i=n-1;i>=0;--i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef double ld;
typedef vector<string> vs;
 
ll mod = 1000000007;
 
void multi(ll F[2][2], ll M[2][2])
{
    ll x = F[0][0]*M[0][0] + F[0][1]*M[1][0],
    y = F[0][0]*M[0][1] + F[0][1] * M[1][1],
    z = F[1][0]*M[0][0] + F[1][1]*M[1][0],
    t = F[1][0]*M[0][1] + F[1][1]*M[1][1];
    F[0][0] = x%mod;
    F[0][1] = y%mod;
    F[1][0] = z%mod;
    F[1][1] = t%mod;
}
 
void power(ll F[2][2], ll n)
{
    if(n==0 || n==1)
        return ;
    ll M[2][2] ={{1,1},{1,0}};
    power(F,n/2);
    multi(F,F);
    if(n%2!=0)
        multi(F,M);
}
 
ll fib(ll n)
{
    ll F[2][2] ={{1,1},{1,0}};
    if(n==0) return 0;
    power(F,n-1);
    return F[0][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<fib(n)<<endl;
    }
    return 0;
}
 