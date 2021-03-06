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

const int Mod = 1000000007;
int n, k;

void Input() {
	cin >> n >> k;
}

void Solve() {
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	for (int i=1; i<min(10, k+1); i++) dp[0][i] = 1;
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<=k; j++) {
			for (int x=0; x<10 && j+x<=k; x++) {
				dp[i+1][j+x] += dp[i][j];
				dp[i+1][j+x] %= Mod;
			}
		}
	}
	cout << dp[n-1][k] << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

