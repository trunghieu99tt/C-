#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i = 0;i<n;i++)

const int maxn = 2000;
int a[maxn][maxn], i, j, adjList[maxn][maxn], counter[maxn];

int main()
{
	int n;
	cin >> n;
	forn(i, n)
	{
		int c = 0;
		forn(j, n)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
				adjList[i][c++] = j + 1;
		}
		counter[i] = c;
	}
	forn(i, n)
	{
		forn(j, counter[i])
			cout << adjList[i][j] << " ";
		cout << endl;
	}
	return 0;
}