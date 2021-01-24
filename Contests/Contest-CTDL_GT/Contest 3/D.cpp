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
priority_queue<long long, vector<long long>, greater<long long>> a;

void Input() {
	cin >> n;
	for (int i=0; i<n; i++) {
		long long x;
		cin >> x; a.push(x);
	}
}

void Solve() {
	long long ans = 0, Mod = 1000000007;
	while (a.size() > 1) {
		long long x = a.top(); a.pop();
		long long y = a.top(); a.pop();
		ans += ((x + y) % Mod);
		ans %= Mod; a.push((x+y) % Mod);
	}
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

