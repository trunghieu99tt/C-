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

string s; int n;

void Input() {
	cin >> s;
	n = s.size();
}

void Solve() {
	int ans = 0;
	for (int i=0; i<n; i++) {
		int L = i, R = i, Len = 1;
		while (L-1 >= 0 && R+1 < n && s[L-1] == s[R+1]) {Len += 2; L--; R++;}
		ans = max(ans, Len);
	}
	for (int i=1; i<n; i++) {
		if (s[i-1] != s[i]) continue;
		int L = i-1, R = i, Len = 2;
		while (L-1 >= 0 && R+1 < n && s[L-1] == s[R+1]) {Len += 2; L--; R++;}
		ans = max(ans, Len);
	}
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

