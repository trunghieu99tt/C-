// Lazy

#include<bits/stdc++.h>

using namespace std;

#define ff first;
#define ss second;

typedef pair<int,int> pii;

vector<pii> t;
vector<int> a;

void push(int v){
	t[2 * v].ff += t[v].ss;
	t[2 * v + 1].ff += t[v].ss;
	t[v].ss = 0;
}


void modify(int v, int l, int r, int ql, int qr,int x){
	t[v].ff += x * (qr - ql);
	if(l == ql && r == qr)
	{
		t[v].ss+=x;
		return;
	}
	int mid = (l + r)>>1;
	if(qr <= mid)
		modify(2 * v, l, mid, ql, qr, x);
	else if modify(2 * v + 1, mid + 1, r, ql,qr,x);
	else{
		modify(2 * v, l, mid, ql, mid, x);
		modify(2 * v + 1, mid, r, mid , qr, x);
	}
}

// Tính tổng trên đoạn [ql,qr] thuộc cây con đỉnh v quản lí đoạn [l,r]

int get(int v, int l,int r, int ql, int qr){
	if(l > qr || r < ql)
		return 0;
	push(v);
	if(ql <= l && r <= qr)
		return t[v].ff;
	int mid = (l + r) >> 1;
	return get(v * 2, l, mid , ql, qr) + get(v * 2 + 1, mid + 1, r , ql, qr);
}

// Phép cập nhật: tăng giá trị các phần tử trên đoạn.
// Đoạn cập nhật: [ql,qr];
// Giá trị cập nhật : x

void update(int v, int l, int r, int ql, int qr, int x){
	if(l == )
}

int main()
{

	return 0;
}