#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> pii;

const int maxn = 505;
const int inf = 1e9;

int d[maxn][maxn], in_queue[maxn][maxn];

int n,m,
	dr[] = {-1,0,0,1},
	dc[] = {0,-1,1,0},
	a[maxn][maxn];

priority_queue<pii, vector<pii> , greater<pii>> q;


void Dijkstra()
{
	d[0][0] = a[0][0];
	int i,j;
	while(!q.empty())
	{
		auto u = q.top(); q.pop(); 
		int w = u.first, r = u.second.first, c = u.second.second;
		for(int i = 0;i<4;i++)
		{
			int x = r + dr[i], y = c + dc[i];
			if(x >=0 && y>=0 && x < n && y< m)
			{
				if(d[x][y] > d[r][c] + a[x][y])
				{
					d[x][y] = d[r][c] + a[x][y];
					q.push(make_pair(d[x][y],make_pair(x,y)));
				}
			}
		}
	}
}

void solve()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int i,j,k;
		for(i = 0;i<n;i++)
			for(j = 0;j<m;j++)
			{
				cin>>a[i][j];
				d[i][j] = inf;
			}
		q.push(make_pair(a[0][0],make_pair(0,0)));
		Dijkstra();
		cout<<d[n-1][m-1]<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	solve();
	return 0;
}