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
 
string A, B;
 
void Input() {
	cin >> A >> B;
}
 
void Solve() {
	int N = A.size();
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	int ptr1L = 0, ptr2L = 0, turn = 0;
	int ptr1R = (N+1)/2 - 1, ptr2R = N/2 - 1;
	string ansL = "", ansR = "";
	while (ansL.size() + ansR.size() < N) {
		if (turn == 0) {
			if (A[ptr1L] < B[ptr2L]) {ansL += A[ptr1L]; ptr1L++;}
			else {ansR += A[ptr1R]; ptr1R--;}
		}
		else {
			if (A[ptr1L] < B[ptr2L]) {ansL += B[ptr2L]; ptr2L++;}
			else {ansR += B[ptr2R]; ptr2R--;}
		}
		turn ^= 1;
	}
	reverse(ansR.begin(), ansR.end());
	cout << ansL << ansR;
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
 
/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/

