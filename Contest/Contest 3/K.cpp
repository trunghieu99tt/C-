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
 
int C, N; vector<int> W;
 
void Input() {
	cin >> C >> N; W.resize(N);
	for (auto &z: W) cin >> z;
}
 
void Solve() {
	vector<vector<int>> dp(N, vector<int>(C+1, 0));
	dp[0][0] = dp[0][W[0]] = 1; int ans = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<=C; j++) {
			if (!dp[i][j]) continue;
			ans = max(ans, j);
			if (i == N-1) continue;
			dp[i+1][j] |= dp[i][j];
			if (j + W[i+1] <= C) dp[i+1][j+W[i+1]] |= dp[i][j];
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

