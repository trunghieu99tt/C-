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

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef double ld;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    int t,k;
    cin>>t;
    forn(k,t)
    {

        int n;
        cin>>n;
        double w[n],c[n];
        int i,j;
        forn(i,n)
            cin>>w[i]>>c[i];
        vi l(n,1);
        for1(i,n)
        {
            forn(j,i)
                if(w[i]>w[j] && c[i]<c[j])
                    l[i] = max(l[i],l[j]+1);
        }
        cout<<*max_element(all(l))<<endl;
    }
    return 0;
}
