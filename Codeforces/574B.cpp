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
    int n,m;
    cin>>n>>m;
    map<int,vi> know;
    int i,j,a,b,k;
    forn(i,m)
    {
        cin>>a>>b;
        know[a].pb(b);
        know[b].pb(a);
    }
    int ans = INT_MAX;
    for1(i,n)
    {
        if(know[i].size()>=2)
        {
            vi temp = know[i];
            for(j = 0;j<temp.size()-1;j++)
            {
                for(k = j+1;k<temp.size();k++)
                {
                    if(find(all(know[temp[j]]),temp[k])!=know[temp[j]].end())
                    {
                        ans = min(ans,(int)temp.size() + (int)know[temp[j]].size() + (int)know[temp[k]].size() - 6);
                    }
                }
            }
        }
    }
    if(ans == INT_MAX)
        cout<<-1;
    else cout<<ans;
    return 0;
}