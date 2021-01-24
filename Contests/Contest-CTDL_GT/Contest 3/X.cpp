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

int n, m; vector<vector<int>> a;

void Input() {
	cin >> n >> m; a.clear();
	a.resize(n, vector<int>(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	vector<vector<int>> dp(n, vector<int>(m, 1000000000));
	dp[0][0] = a[0][0];
	queue<pair<int, int>> Q; Q.push({0, 0});
	while (!Q.empty()) {
		pair<int, int> P = Q.front(); Q.pop();
		int x = P.first, y = P.second;
		if (x + 1 < n) {
			if (dp[x+1][y] == 1000000000) Q.push({x+1, y});
			dp[x+1][y] = min(dp[x+1][y], dp[x][y] + a[x+1][y]);
		}
		if (y + 1 < m) {
			if (dp[x][y+1] == 1000000000) Q.push({x, y+1});
			dp[x][y+1] = min(dp[x][y+1], dp[x][y] + a[x][y+1]);
		}
		if (x + 1 < n && y + 1 < m) {
			if (dp[x+1][y+1] == 1000000000) Q.push({x+1, y+1});
			dp[x+1][y+1] = min(dp[x+1][y+1], dp[x][y] + a[x+1][y+1]);
		}
	}
	cout << dp[n-1][m-1] << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

