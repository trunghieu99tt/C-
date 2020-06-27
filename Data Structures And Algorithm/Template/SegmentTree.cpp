#include <bits/stdc++.h>

const int maxn = 1e5;

int n;

int t[2 * maxn];

void build()
{
	for (int i = n - 1; i > 0; i--)
		t[i] = t[i << 1] + t[i << 1 | 1];
}

// set value at position p
void modifySingle(int p, int value)
{
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p >> 1] = t[p] + t[p ^ 1];
}

void modifyRange(int l, int r, int value)
{
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			t[l++] += value;
		if (r & 1)
			t[--r] += value;
	}
}

// sum on interval [l,r)
int sumQuery(int l, int r)
{
	int res = 0;
	// if want sum on intervall [l,r]
	// for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res += t[l++];
		if (r & 1)
			res += t[--r];
	}
	return res;
}

// Return the value of element at index p
int query(int p)
{
	int ans = 0;
	for (p += n; p > 0; p >>= 1)
		ans += t[p];
	return ans;
}

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[n + i];
	build();
	modifySingle(0, 2);
	cout << sumQuery(3, 11);
	return 0;
}