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

int x0, y0;

void Input() {
	cin >> x0 >> y0;
}

void Solve() {
	int mul = 1, x1 = 0, x2 = 0;
	while (x0 > 0) {
		int z = x0 % 10; x0 /= 10;
		if (z == 6) x1 += mul * 5;
		else x1 += mul * z;
		if (z == 5) x2 += mul * 6;
		else x2 += mul * z;
		mul *= 10;
	}
	mul = 1; int y1 = 0, y2 = 0;
	while (y0 > 0) {
		int z = y0 % 10; y0 /= 10;
		if (z == 6) y1 += mul * 5;
		else y1 += mul * z;
		if (z == 5) y2 += mul * 6;
		else y2 += mul * z;
		mul *= 10;
	}
	cout << (x1 + y1) << " ";
	cout << (x2 + y2) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

