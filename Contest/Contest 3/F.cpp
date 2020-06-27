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

int n, k; string s;

void Input() {
	cin >> n >> k >> s;
}

void Solve() {
	stack<int> Stack;
	for (auto ch: s) {
		while (!Stack.empty() && (ch - '0') > Stack.top() && k > 0) {Stack.pop(); k--;}
		Stack.push(ch-'0');
	}
	while (k > 0 && !Stack.empty()) {Stack.pop(); k--;}
	string ans = "";
	while (!Stack.empty()) {ans += char(Stack.top() + 48); Stack.pop();}
	reverse(ans.begin(), ans.end()); cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

