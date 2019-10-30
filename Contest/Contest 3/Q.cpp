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
 
int n, s; vector<int> a;
 
void Input() {
	cin >> n >> s; a.resize(n);
	for (auto &z: a) cin >> z;
}
 
void Solve() {
	vector<vector<int>> dp(n, vector<int>(s+1, 0));
	dp[0][0] = dp[0][a[0]] = 1;
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<=s; j++) {
			dp[i+1][j] |= dp[i][j];
			if (j+a[i+1]) dp[i+1][j+a[i+1]] |= dp[i][j];
		}
	}
	if (dp[n-1][s]) cout << "YES\n";
	else cout << "NO\n";
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
 
/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

