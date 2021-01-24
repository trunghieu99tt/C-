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
	cin >> n; a.clear();
	a.resize(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	vector<int> perm(n); for (int i=0; i<n; i++) perm[i] = i;
	long long ans = 0, maxSecond = -1000000000000000000LL;
	do {
		long long Fi = 0, Se = 0;
		for (int i=0; i<n; i++) {
			int j = perm[i];
			Fi += a[i][j];
			Se -= a[i][j];
		}
		if (Se > maxSecond) {maxSecond = Se; ans = Fi;}
		else if (Se == maxSecond) ans = min(ans, Fi);
	} while (next_permutation(perm.begin(), perm.end()));
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

