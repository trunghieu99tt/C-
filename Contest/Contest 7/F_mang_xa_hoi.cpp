#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5;

int n,m;

int a[maxn], b[maxn];
map<int,vector<int>> adjList;
map<int,int> visited;

void dfs(int u, int &cntEdge, int &cntVertices)
{
    cntEdge+= adjList[u].size();
    cntVertices++;
    visited[u] = 1;
    for(auto i:adjList[u])
    {
        if(!visited[i])
            dfs(i,cntEdge,cntVertices);
    }
}

void trunghieu()
{
    int t;
    cin>>t;
    while(t--)
    {
    	adjList.clear();
    	visited.clear();
        cin>>n>>m;
        int i,j, flag = 1;
        for(i = 0;i<m;i++)
        {
            cin>>a[i]>>b[i];
            adjList[a[i]].emplace_back(b[i]);
            adjList[b[i]].emplace_back(a[i]);
        }
        for(i = 1;i<=n;i++)
        {
            if(visited[i] == 0)
            {
                int cntEdge = 0, cntVertices = 0;
                dfs(i,cntEdge,cntVertices);
                if(cntEdge != 1LL*cntVertices * (cntVertices - 1))
                {
                    cout<<"NO\n";
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
        	cout<<"YES\n";
    }
}

int main()
{
    // cerr << "Program is running" << endl;
    // t1 = clock();
    ios::sync_with_stdio(false);
    cin.tie();
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     //freopen("output.txt","w",stdout);
    // #endif
    trunghieu();
    // t2 = clock();
    // float diff ((float)t2-(float)t1);
    // float seconds = diff / CLOCKS_PER_SEC;
    // cerr << "\nRunning in " << seconds << " seconds" << endl;
    return 0;
}