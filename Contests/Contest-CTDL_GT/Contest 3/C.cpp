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

int n;

void Input() {
	cin >> n;
}

void Solve() {
	for (int seven=n/7; seven>=0; seven--) {
		if ((n - seven * 7) % 4 != 0) continue;
		int four = (n - seven * 7) / 4;
		for (int x=0; x<four; x++) cout << "4";
		for (int x=0; x<seven; x++) cout << "7";
		cout << endl; return;
	}
	cout << "-1\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

