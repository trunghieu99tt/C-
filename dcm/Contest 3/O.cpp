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
 
string s, t;
int n, m;

int LCS(vector<vector<int>> &dp, int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i == 0 || j == 0) dp[i][j] = 0;
	else if (s[i-1] == t[j-1]) dp[i][j] = (LCS(dp, i-1, j-1) + 1);
	else dp[i][j] = max(LCS(dp, i-1, j), LCS(dp, i, j-1));
	return dp[i][j];
}
 
void Input() {
	cin >> s >> t;
	n = s.size(); m = t.size();
}
 
void Solve() {
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	cout << LCS(dp, n, m) << endl;
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
 
/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

