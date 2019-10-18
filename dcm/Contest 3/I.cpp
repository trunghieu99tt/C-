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
 
int n; vector<int> a;
 
void Input() {
	cin >> n; a.clear(); a.resize(n);
	for (auto &z: a) cin >> z;
}
 
void Solve() {
	sort(a.begin(), a.end());
	int Min = a[n-1] - a[n-2] + 1;
	int Max = a[n-1] + a[n-2] - 1;
	auto Mn = lower_bound(a.begin(), a.begin()+n-2, Min);
	auto Mx = upper_bound(a.begin(), a.begin()+n-2, Max);
	if (Mx - Mn > 0) cout << "YES\n";
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

