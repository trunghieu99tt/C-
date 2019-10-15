#include<bits/stdc++.h>

using namespace std;

#define maxn 20

int n;

int fOPT = INT_MAX, i, j;

int x[maxn], unvisited[maxn], cmin;

int cost[maxn + 1][maxn + 1], l = 0, ans = INT_MAX, g = 0;

void init()
{
	x[1] = 1;
	for (i = 0;i <= n;i++)
		unvisited[i] = 1;
}

void solve(int k)
{
	for (int j = 2;j <= n;j++)
	{
		if (unvisited[j])
		{
			x[k] = j;
			unvisited[j] = 0;
			l+=cost[x[k - 1]][x[k]];
			if (k == n)
			{
				ans = min(ans,l + cost[x[k]][1]);
			}
			else if (l + (n-k+1)*cmin < ans)
				solve(k + 1);
			unvisited[j] = 1;
			l -= cost[x[k - 1]][x[k]];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cmin = INT_MAX;
	cin >> n;
	for(i = 1;i<=n;i++)
		for(j = 1;j<=n;j++)
		{
			cin >> cost[i][j];
			if (cost[i][j] != 0)
				cmin = min(cmin, cost[i][j]);
		}
	init();
	solve(2);
	cout << ans<<endl;
	return 0;
}