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
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}
 
void Solve() {
	vector<int> LIS;
	for (int i=0; i<n; i++) {
		int id = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
		if (id == LIS.size()) LIS.push_back(a[i]);
		else LIS[id] = a[i];
	}
	cout << LIS.size() << endl;
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
 
/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

