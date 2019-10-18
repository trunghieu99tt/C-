// Lazy

#include <bits/stdc++.h>

using namespace std;
struct node
{
	int ll, rr, id;

	node(int L, int R, int X)
	{
		ll = L, rr = R, id = X;
		lazy_update();
	}

	node left()
	{
		return node(ll, (ll + rr) / 2, id * 2);
	}
	node right()
	{
		return node((ll + rr) / 2 + 1, rr, id * 2 + 1);
	}

	void lazy_update()
	{
		if (Lazy[id] == -1)
			return; // assume that -1 is unused value
		if (ll != rr)
			Lazy[id * 2] = Lazy[id * 2 + 1] = Lazy[id];
		Max[id] = Lazy[id];
		Lazy[id] = -1;
	}

	void assign_range(int L, int R, int X)
	{ // don't need to call lazy_update() at the beginning
		if (ll > R || L > rr)
			return;
		if (L <= ll && rr <= R)
		{
			Lazy[id] = X;
			lazy_update();
			return;
		}
		left().assign_range(L, R, X); // easier to read
		right().assign_range(L, R, X);
		Max[id] = max(Max[id * 2], Max[id * 2 + 1]);
	}

	int max_range(int L, int R)
	{
		if (ll > R || L > rr)
			return -oo;
		if (L <= ll && rr <= R)
			return Max[id];
		int Max1 = left().max_range(L, R);
		int Max2 = right().max_range(L, R);
		return max(Max1, Max2);
	}
};
int main()
{

	return 0;
}