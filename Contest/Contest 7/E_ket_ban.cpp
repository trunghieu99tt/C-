#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)

const int maxn = 2e5;

int n,m;

int a[maxn], b[maxn];
gp_hash_table<int,vector<int>> adjList;
gp_hash_table<int,int> visited;

void dfs(int u, int &cntEdge, int &cntVertices)
{
    cntEdge+= adjList[u].size();
    cntVertices++;
    visited[u] = 1;
    for(auto i:adjList[u])
        if(!visited[i])
            dfs(i,cntEdge,cntVertices);
}

void trunghieu()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int i,j, ans = 0;
        visited.clear();
        adjList.clear();
        forn(i,m)
        {
            cin>>a[i]>>b[i];
            adjList[a[i]].emplace_back(b[i]);
            adjList[b[i]].emplace_back(a[i]);
        }
        for1(i,n)
            if(visited[i] == 0)
            {
                int cntEdge = 0, cntVertices = 0;
                dfs(i,cntEdge,cntVertices);
                ans = max(ans,cntVertices);
            }
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    trunghieu();
    return 0;
}