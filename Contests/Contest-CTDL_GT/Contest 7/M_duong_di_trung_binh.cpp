#include<bits/stdc++.h>

using namespace std;

const int maxn = 105;

int n,m;

map<int,vector<int>> adjList;
map<int,int> visited,path;

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		double ans = 0.0;
		int cnt = 0;
		adjList.clear();
		cin>>n>>m;
		int i,j;
		for(i = 0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			adjList[u].emplace_back(v);
		}
		visited.clear();
		for(int i = 1;i<=n;i++)
		{
			if(!visited[i])
			{
				queue<int> q;
				path.clear();
				vector<int> point;
				point.emplace_back(i);
				path[i] = 0;
				visited[i] = 1;
				q.push(i);
				while(!q.empty())
				{
					int u = q.front();
					q.pop();
					for(auto v:adjList[u])
					{
						if(!visited[v])
						{
							visited[v] = 1;
							q.push(v);
							point.emplace_back(v);
						}
					}
				}
				for(auto u:point)
				{
					queue<int> q1;
					q1.push(u);
					map<int,int> dist;
					dist[u] = 0;
					map<int,int> visited1;
					visited1[u] = 1;
					while(!q1.empty())
					{
						int u1 = q1.front();q1.pop();
						for(auto v:adjList[u1])
						{
							if(!visited1[v])
							{
								visited1[v] = 1;
								q1.push(v);
								dist[v] = dist[u1] + 1;
								ans+= dist[v];
								cnt++;
							}
						}
					}
				}
			}
		}
		cout<<setprecision(2)<<fixed<<ans/cnt<<endl;
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