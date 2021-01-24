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

int n, Max; vector<vector<int>> a;

bool inteferred(int mask1, int mask2) {
	for (int i=0; i<4; i++) {
		if (((mask1 >> i) & 1) && ((mask2 >> i) & 1)) {
			return true;
		}
	}
	return false;
}

bool selfInteferred(int mask) {
	for (int i=0; i<3; i++) {
		if (((mask >> (i+0)) & 1) && ((mask >> (i+1)) & 1)) {
			return true;
		}
	}
	return false;
}

void Input() {
	Max = -1000000000;
	cin >> n; a.clear();
	a.resize(4, vector<int>(n));
	for (int i=0; i<4; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
			Max = max(Max, a[i][j]);
		}
	}
}

void Solve() {
	if (Max < 0) {cout << Max << endl; return;}
	vector<vector<int>> dp(n, vector<int>(1 << 4, -1000000000));
	for (int i=0; i<16; i++) {
		if (selfInteferred(i)) continue;
		dp[0][i] = 0;
		for (int x=0; x<4; x++) {
			if ((i >> x) & 1) dp[0][i] += a[x][0];
		}
	}
	for (int i=0; i<n-1; i++) {
		for (int mask=0; mask<16; mask++) {
			if (selfInteferred(mask)) continue;
			for (int newmask=0; newmask<16; newmask++) {
				if (selfInteferred(newmask)) continue;
				if (inteferred(mask, newmask)) continue;
				int tmp = 0;
				for (int x=0; x<4; x++) {
					if ((newmask >> x) & 1) tmp += a[x][i+1];
				}
				dp[i+1][newmask] = max(dp[i+1][newmask], dp[i][mask] + tmp);
			}
		}
	}
	cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

