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
typedef vector<vs> vvs;

int maxValue(int w[], int maxW, int n)
{
    if(maxW == 0 || n == 0)
        return 0;
    if(w[n-1] > maxW)
        return maxValue(w,maxW,n-1);
    else
        return max(maxValue(w,maxW - w[n-1],n-1) + w[n-1], maxValue(w,maxW,n-1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    int maxW, n;
    cin>>maxW>>n;
    int w[n],i;
    forn(i,n)
        cin>>w[i];
    cout<<maxValue(w,maxW,n);
    return 0;
}
