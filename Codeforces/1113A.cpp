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
    int n,v;
    cin>>n>>v;
    int i,curr = 0, ans = 0;
    for(i = 1;i<n;i++)
    {
        if(n - i > curr)
        {
            if(curr < v)
            {
                ans+= i * (min(v - curr, n - i - curr));
                curr += min(v - curr, n - i - curr);
            }
        }
        curr--;
    }
    cout<<ans;
    return 0;
}