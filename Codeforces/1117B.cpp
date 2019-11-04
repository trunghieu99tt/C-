#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n,m,k;
    cin>>n>>m>>k;
    int a[n],i,j;
    forn(i,n)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    int cnt = 0, first = 1;
    int num = m/(k + 1);
    ll ans = 0;
    ans+= num * (a[0] * k + a[1]) ;
    ans+= a[0] * (m - num * (k+1));
    cout<<ans;
    return 0;
}