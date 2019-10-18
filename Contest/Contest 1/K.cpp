#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;

map<int, int> div(int n)
{
	map<int, int> ans;
	for (int i = 2;i*i <= n;i++)
	{
		if (n%i == 0)
		{
			int counter = 0;
			while (n%i == 0)
			{
				counter++;
				n /= i;
			}
			ans[i] = counter;
		}
	}
	if (n != 1)
		ans[n] = 1;
	return ans;
}

bool checkPrime(int n)
{
	if (n < 2)
		return 0;
	if (n <= 3)
		return 1;
	if (n % 2 == 0 || n % 3 == 0)
		return 0;
	int i = 5;
	while (i*i <= n)
	{
		if (n%i == 0 || n % (i + 2) == 0)
			return 0;
	}
	return 1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	int t, k;
	cin >> t;
	forn(k, t)
	{
		int n, i, j;
		cin >> n;
		ll ans = LLONG_MAX;
		map<int, int> fac = div(n);
		vector<int> x, y;
		map<int, int>::iterator it;
		vvi allPos;
		vi first;
		for (it = fac.begin(); it != fac.end();it++)
			first.pb(round(pow(it->first, it->second)));
		queue<vi> q;
		q.push(first);
		while (!q.empty())
		{
			vi u = q.front();
			for(auto i:u)
				cout<<i<<" ";
			cout<<endl;
			q.pop();
			allPos.pb(u);
			for (i = 0;i < u.size();i++)
			{
				for (j = 2;j*j <= u[i];j++)
				{
					if (u[i] % j == 0)
					{
						vi t = u;
						t.erase(t.begin() + i);
						t.pb(j);
						t.pb(u[i] / j);
						q.push(t);
					}
				}
			}
		}
		forn(i, allPos.size())
		{
			ll tmp = 1;
			int prime = 2;
			sort(all(allPos[i]), greater<int>());
			for(auto j:allPos[i])
				cout<<j<<" ";
			cout<<endl;
			forn(j, allPos[i].size())
			{
				while (!checkPrime(prime))
					prime++;
				tmp *= round(pow(prime, allPos[i][j] - 1));
				prime++;
			}
			if (tmp > 0)
				ans = min(tmp, ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}