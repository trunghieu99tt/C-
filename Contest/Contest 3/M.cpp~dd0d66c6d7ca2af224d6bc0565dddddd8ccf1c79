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
 
int n; vector<string> a;
 
void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}
 
void Solve() {
	vector<vector<int>> dup(n, vector<int>(n, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			vector<int> cnti(26, 0), cntj(26, 0);
			for (auto ch: a[i]) cnti[ch-'A']++;
			for (auto ch: a[j]) cntj[ch-'A']++;
			for (int x=0; x<26; x++) dup[i][j] += (cnti[x] > 0 && cntj[x] > 0);
		}
	}
	vector<int> perm(n); for (int i=0; i<n; i++) perm[i] = i;
	int ans = 1000000000;
	do {
		int tmp = 0;
		for (int i=1; i<n; i++) {
			tmp += dup[perm[i-1]][perm[i-0]];
		}
		ans = min(ans, tmp);
	} while (next_permutation(perm.begin(), perm.end()));
	cout << ans << endl;
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
 
/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

