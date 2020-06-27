#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
using namespace std;
 
#define y0 holdtheflower
#define y1 enjoythecolorandscent
#define yn walkthroughthesoulgarden
#define j1 feelthewarmbreathofkindnessandsalvation
 
#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
 
int n; vector<vector<int>> a;
 
void Input() {
	cin >> n; a.resize(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
}
 
void Solve() {
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(1 << n, vector<int>(n, 1000000000)));
	queue<pair<pair<int, int>, int>> Q;
	for (int i=0; i<n; i++) {
		dp[i][1 << i][i] = min(dp[i][1 << i][i], 0);
		Q.push(make_pair(make_pair(i, 1 << i), i));
	}
	while (!Q.empty()) {
		pair<pair<int, int>, int> T = Q.front(); Q.pop();
		int st = T.first.first, mask = T.first.second, last = T.second;
		for (int x=0; x<n; x++) {
			if ((mask >> x) & 1) continue;
			int newmask = mask | (1 << x);
			if (dp[st][newmask][x] == 1000000000) Q.push(make_pair(make_pair(st, newmask), x));
			int val = dp[st][mask][last] + a[last][x];
			if (newmask == ((1 << n) - 1)) val += a[x][st];
			dp[st][newmask][x] = min(dp[st][newmask][x], val);
		}
	}
	int ans = 1000000000;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			ans = min(ans, dp[i][(1 << n) - 1][j]);
		}
	}
	cout << ans << endl;
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
 
/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

