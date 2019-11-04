#include <bits/stdc++.h>

#define forn(i, n) for (i = 0; i < n; ++i)

#define for1(i, n) for (i = 1; i <= n; ++i)

#define pb push_back

#define all(x) (x).begin(), (x).end()

#define mp make_pair

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<vi> vvi;

typedef vector<vll> vvll;

typedef vector<string> vs;

typedef vector<vs> vvs;

int main()

{

	ios::sync_with_stdio(false);

	cin.tie();

	//freopen("input.txt","r",stdin);

	//freopen("output.txt","w",stdout);

	int n, k;

	cin >> n >> k;

	string s;

	cin >> s;

	map<char, vector<string>> str;

	int i = 0;

	while (i < n)

	{

		string temp = "";

		while (s[i] == s[i + 1] && i < n)

		{

			temp += s[i];

			i++;
		}

		temp += s[i];

		if (temp.size() >= k)

			str[s[i]].pb(temp);

		i++;
	}

	int ans = INT_MIN;

	for (auto i : str)

	{

		int minLen = INT_MAX;

		for (auto j : i.second)

			minLen = min(minLen, (int)(j.size()));

		int x = 0;

		minLen = min(k, minLen);

		for (auto j : i.second)

			x += j.size() / minLen;

		if (minLen == k)

			ans = max(x, ans);
	}

	if (ans == INT_MIN)

		cout << 0 << endl;

	else
		cout << ans << endl;

	return 0;
}