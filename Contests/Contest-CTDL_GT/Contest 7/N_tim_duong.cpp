#include<bits/stdc++.h>

using namespace std;

int dr[] = {1,0,-1,0},
	dc[] = {0,1,0,-1};

bool visited[505][505][4][4];

char a[505][505];

int n, m, xs, ys, xe, ye;
int flag = 0;

bool valid(int x, int y){
	return x >= 0 && x < n && y >=0 && y < m && a[x][y]!='*';
}

void dfs(int x, int y, int d, int k){
	if(visited[x][y][d][k] || flag)
		return;
	visited[x][y][d][k] = 1;
	if(x == xe && y == ye){
		cout<<"YES\n";
		flag = 1;
		return;
	}
	int xx = x + dr[d], yy = y + dc[d];
	if(valid(xx,yy))
		dfs(xx,yy,d,k);
	if(k)
	{
		for(int i = -1;i<2;i++)
		{
			if(!i)
				continue;
			int dd = (d + 4 + i )%4;
			xx = x + dr[dd], yy = y + dc[dd];
			if(valid(xx,yy))
				dfs(xx,yy,dd,k-1);
		}
	}
}

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		flag = 0;
		cin>>n>>m;
		int i,j;
		for(i = 0;i<n;i++)
			for(j = 0;j<m;j++)
			{
				cin>>a[i][j];
				if(a[i][j] == 'S')
					xs = i, ys = j;
				else if(a[i][j] == 'T')
					xe = i, ye = j;
			}
		for(i = 0;i<4;i++)
			dfs(xs,ys, i, 2);
		if(!flag)
			cout<<"NO\n";
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