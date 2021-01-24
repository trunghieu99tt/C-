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
	vector<int> dp(n, 0);
	int sum = 0;
	for (int i=0; i<n; i++) {
		dp[i] = (sum + (i < k)) % Mod;
		sum = (sum + dp[i]) % Mod;
		if (i >= k) sum = (sum + Mod - dp[i-k]) % Mod;
	}
	cout << dp[n-1] << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

