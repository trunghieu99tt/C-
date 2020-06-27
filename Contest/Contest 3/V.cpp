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

int getSquare(int x1, int y1, int d) {
	int res = a[x1+d-1][y1+d-1];
	if (x1 > 0) res -= a[x1-1][y1+d-1];
	if (y1 > 0) res -= a[x1+d-1][y1-1];
	if (x1 > 0 && y1 > 0) res += a[x1-1][y1-1];
	return res;
}

bool exists(int d) {
	for (int i=0; i+d-1<n; i++) {
		for (int j=0; j+d-1<m; j++) {
			if (getSquare(i, j, d) == d * d) return true;
		}
	}
	return false;
}

int binsearch(int top, int bot) {
	int res = 0;
	while (top <= bot) {
		int mid = (top + bot) / 2;
		if (exists(mid)) {res = mid; top = mid + 1;}
		else bot = mid - 1;
	}
	return res;
}

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
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i > 0) a[i][j] += a[i-1][j];
			if (j > 0) a[i][j] += a[i][j-1];
			if (i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
		}
	}
	cout << binsearch(1, min(n, m)) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

