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

bool valid(int a[], int b[], double x, int n, int m)
{
    int i, fly = 1;
    double feul = (m + x) * 1.0 / a[0];
    x-=feul;
    if(x < 0)
        return 0;
    for(i = 1;i<n;i++)
    {
        feul = (m + x) * 1.0 / b[i];
        x-=feul;
        if(x < 0)
            return 0;
        feul = (m + x) * 1.0 / a[i];
        x-= feul;
        if(x < 0)
            return 0;
    }
    feul = (m + x) * 1.0 / b[0];
    x-=feul;
    if(x < 0)
        return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n], b[n],i,j, flag = 0;
    forn(i,n)
        cin>>a[i];
    forn(i,n)
        cin>>b[i];
    double lo = 0.0, hi = 1e18, mid = 0.0, ans = -1.0;
    for(i = 0;i<100;i++)
    {
        mid = (lo + hi) / 2.0;
        if(valid(a,b,mid,n,m))
        {
            flag = 1;
            ans = mid;
            hi = mid;
        }
        else lo = mid;
    }
    if(flag == 0)
        cout<<-1;
    else if(ans >= 0)
    cout<<setprecision(20)<<fixed<<ans;
    return 0;
}