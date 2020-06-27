#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)

using namespace std;

int ans = 0, a[5], i, flag = 0;

void solve(int u)
{
	for(int i = 0;i<3;i++)
	{
		switch (i)
		{
			case 0: ans += a[u];break;
			case 1: ans -= a[u];break;
			case 2: ans *= a[u];break;
		}
		if (u == 4)
		{
			if (ans == 23)
			{
				flag = 1;
				return;
			}
		}
		else
			solve(u + 1);
		switch (i)
		{
			case 0: ans -= a[u];break;
			case 1: ans += a[u];break;
			case 2: ans /= a[u];break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t, k;
	cin >> t;
	forn(k, t)
	{
		int ok = 0;
		forn(i, 5)
			cin >> a[i];
		sort(a, a + 5);
		do{
			flag = 0;
			ans = a[0];
			solve(1);
			if(flag)
			{
				ok = 1;
				break;
			}
		}
		while(next_permutation(a,a+5));
		if (ok)
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}