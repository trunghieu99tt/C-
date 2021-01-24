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
vector<int> ftrl(1001, 1);

int modPow(int a, int b, int res = 1) {
	while (b > 0) {
		if (b % 2) {b--; res = (1LL * res * a) % Mod;}
		else {b /= 2; a = (1LL * a * a) % Mod;}
	}
	return res;
}

int nCr(int n, int r) {
	int numer = ftrl[n];
	int denom = (1LL * ftrl[n-r] * ftrl[r]) % Mod;
	return ((1LL * numer * modPow(denom, Mod-2)) % Mod);
}

void Preprocess() {
	for (int i=1; i<1001; i++) ftrl[i] = (1LL * ftrl[i-1] * i) % Mod;
}

void Input() {
	cin >> n >> k;
}

void Solve() {
	cout << nCr(n, k) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL); Preprocess();
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

