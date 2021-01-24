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
 
int n; vector<long long> a;
 
void Input() {
	cin >> n; a.clear(); a.resize(n);
	for (auto &z: a) cin >> z;
}
 
void Solve() {
	long long G = 0;
	for (auto x: a) G = __gcd(G, x);
	if (G != 1) {cout << "YES 0\n"; return;}
	if (n == 1) {cout << "NO\n"; return;}
	G = 0; int cnt = 0;
	for (int i=0; i<n; i++) {
		if (a[i] % 2 == 0) continue;
		int j = i; while (j+1 < n && a[j+1] % 2 != 0) j++;
		int Len = (j - i + 1); cnt += (Len / 2) + (Len % 2) * 2;
		i = j;
	}
	for (auto x: a) G = __gcd(G, x);
	if (cnt > 0) cout << "YES " << cnt << endl;
	else cout << "NO\n";
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}
 
/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

