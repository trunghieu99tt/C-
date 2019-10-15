#include<bits/stdc++.h>

using namespace std;

const int maxn = 1005;
const int inf = 1e9;

long long a[maxn][maxn], n , m, cost[maxn][maxn];


void solve()
{
	cin>>n>>m;
	int i,j, k ;
	for(i = 1;i<=n;i++)
		for(j = 1;j<=n;j++)
			if(i != j)
				cost[i][j] = inf;
			else cost[i][j] = 0;
	int u, v, c;
	for(i = 0;i<m;i++)
	{
		cin>>u>>v>>c;
		cost[u][v] = c;
		cost[v][u] = c;
	}
	for(k = 1;k<=n;k++)
		for(i = 1;i<=n;i++)
			for(j = 1;j<=n;j++)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
	int q;
	cin>>q;
	while(q--)
	{
		int x, y;
		cin>>x>>y;
		cout<<cost[x][y]<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}