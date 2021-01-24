#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void next_per(string &s, int n)
{
	int i = n - 1;
	while (s[i] == '1')
		i--;
	s[i] = '1';
	for (int j = i + 1;j < n;j++)
		s[j] = '0';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n, sum;
	cin >> n >> sum;
	int a[n], i, j, ans = INT_MAX;
	forn(i, n)
		cin >> a[i];
	map<int, vi> amountWithValueA, amountWithValueB;
	if (n % 2 == 0)
	{
		string s(n / 2, '0');
		do
		{
			int sumA = 0, sumB = 0, cnt = count(all(s), '1');
			forn(i, n / 2)
			{
				sumA += (s[i] - '0') * a[i];
				sumB += (s[i] - '0') * a[i + n / 2];
			}
			amountWithValueA[sumA].pb(cnt);
			amountWithValueB[sumB].pb(cnt);
			next_per(s, n / 2);
		} while (count(all(s), '1') != s.size());
		int sumA = 0, sumB = 0;
		forn(i, n / 2)
		{
			sumA += (s[i] - '0') * a[i];
			sumB += (s[i] - '0') * a[i + n / 2];
		}
		amountWithValueA[sumA].pb(s.size());
		amountWithValueB[sumB].pb(s.size());
	}
	else
	{
		string s1(n / 2, '0'), s2(n / 2 + 1, '0');
		do
		{
			int cnt = count(all(s1), '1'), sumA = 0;
			forn(i, n / 2)
				sumA += (s1[i] - '0') * a[i];
			amountWithValueA[sumA].pb(cnt);
			next_per(s1, n / 2);
		} while (count(all(s1), '1') != s1.size());
		int sumA = 0;
		forn(i, n / 2)
			sumA += (s1[i] - '0') * a[i];
		amountWithValueA[sumA].pb(s1.size());
		do {
			int cnt = count(all(s1), '1'), sumB = 0;
			forn(i, n / 2 + 1)
				sumB += (s2[i] - '0') * a[i + n / 2];
			amountWithValueB[sumB].pb(cnt);
			next_per(s2, n / 2 + 1);
		} while (count(all(s2), '1') != s2.size());
		int sumB = 0;
		forn(i, n / 2 + 1)
			sumB += (s2[i] - '0') * a[i + n / 2];
		amountWithValueA[sumA].pb(s2.size());
	}
	map<int, vi>::iterator it;
	for (it = amountWithValueA.begin(); it != amountWithValueA.end();it++)
		sort(all(amountWithValueA[it->first]));
	for (it = amountWithValueB.begin(); it != amountWithValueB.end();it++)
		sort(all(amountWithValueB[it->first]));
	for (it = amountWithValueA.begin();it != amountWithValueA.end();it++)
	{
		if (amountWithValueB[sum - it->first].size() > 0)
			ans = min(ans, it->second[0] + amountWithValueB[sum - it->first][0]);
	}
	if(ans!=INT_MAX)
		cout << ans << endl;
	else cout<<-1;
	return 0;
}