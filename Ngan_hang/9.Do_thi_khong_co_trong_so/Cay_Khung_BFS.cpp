#include<bits/stdc++.h>

using namespace std;

void solve()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,u;
		cin>>n>>m>>u;
		int i,j, flag = 1;
		map<int,vector<int>> adjList;
		map<int,int> visited;
		vector<pair<int,int>> ans;
		for(i = 0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			adjList[a].emplace_back(b);
			adjList[b].emplace_back(a);
		}
		queue<int> q;
		q.push(u);
		visited[u] = 1;
		while(!q.empty())
		{
			int top = q.front();q.pop();
			for(auto v:adjList[top]){
				if(!visited[v]){
					q.push(v);
					visited[v] = 1;
					ans.emplace_back(make_pair(top,v));
				}
			}
		}
		for(i = 1;i<=n;i++)
			if(!visited[i]){
				flag = 0;
				break;
			}
		if(flag){
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