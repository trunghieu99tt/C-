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

int n; int a[15][15];
int dp[15][1 << 15];
pair<int, int> Q[(1 << 15) * 15];

void Input() {
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<(1<<n); j++) {
			dp[i][j] = 1000000000;
		}
	}
}

void Solve() {
	int Front = 0, Back = -1;
	for (int i=0; i<n; i++) {
		dp[i][1 << i] = 0;
		Q[++Back] = {i, 1 << i};
	}
	int ans = 1000000000;
	while (Front <= Back) {
		pair<int, int> T = Q[Front++];
		int last = T.first, mask = T.second;
		if (mask == (1 << n) - 1) ans = min(ans, dp[last][mask]);
		for (int x=0; x<n; x++) {
			if ((mask >> x) & 1) continue;
			int newmask = mask | (1 << x);
			if (dp[x][newmask] == 1000000000) Q[++Back] = {x, newmask};
			dp[x][newmask] = min(dp[x][newmask], dp[last][mask] + a[last][x]);
		}
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

