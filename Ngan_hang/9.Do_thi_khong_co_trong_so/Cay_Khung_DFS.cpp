#include<bits/stdc++.h>

using namespace std;

map<int,int> visited;
map<int,vector<int>> adjList;
vector<pair<int,int>> ans;

void dfs(int u){
	visited[u] = 1;
	for(auto v:adjList[u]){
		if(!visited[v]){
			ans.emplace_back(make_pair(u,v));
			dfs(v);
		}
	}
}

void solve()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,u;
		cin>>n>>m>>u;
		int i,j;
		adjList.clear();visited.clear();ans.clear();
		int flag = 1;
		for(i = 0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			adjList[a].emplace_back(b);
			adjList[b].emplace_back(a);
		}
		dfs(u);
		for(i = 1;i<=n;i++)
			if(!visited[i])
			{
				flag = 0;
				break;
			}
		if(flag)
		{
			for(auto i:ans)
				cout<<i.first<<" "<<i.second<<endl;
		}
		else cout<<-1<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	solve();
	return 0;
}