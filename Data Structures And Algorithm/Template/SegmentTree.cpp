#include<bits/stdc++.h>

using namespace std;

vector<int> d,a;

// Thiết lập cây
// Sử dụng đệ quy
// Giả sử truy vấn trên đoạn là tính tổng trên đoạn.
// lời gọi: build(1,0,n)
void build(int v, int l, int r){
	if(l == r)
		d[v] = a[l];
	else
	{
		int mid = (l + r)>>1;
		build(v * 2, l,mid);
		build(v * 2 + 1, mid + 1, r);
		d[v] = d[v * 2] + d[v * 2 + 1];
	}
}

// Thay đổi giá trị một phần tử
// a[pos] nhận giá trị mới là val (0 <= pos <= n - 1)
// Goị: update(1,0,n,pos,val);
void update(int v, int l, int r, int pos , int val){
	if(l == r)
		d[v] = val, a[l] = val;
	else{
		int mid = (l + r) >> 1;
		if(pos <= mid)
			update(v * 2, l, mid, pos, val);
		else update(v * 2 + 1, mid + 1, r, pos, val);
	}
}

// Lấy giá trị trong đoạn từ ql đến qr
int get(int v, int l, int r, int ql, int qr){
	if(l > qr || r < ql)
		return 0;
	if(ql <= l && r <= qr)
		return d[v];
	int mid = (l + r)>>1;
	return get(v * 2, l,mid, ql, qr) + get(v * 2 + 1, mid + 1, r, ql, qr);
}


int main(){
	freopen("input.txt","r",stdin);
	int n,q;
	cin>>n>>q;
	a.assign(2 * n , 0);
	d.assign(4 * n + 4, 0);
	for(int i = 0;i<n;i++)
		cin>>a[i];
	build(1,0,n);
	long long ans = 0;
	while(q--){
		int l, r;
		cin>>l>>r;
		l--;r--;
		ans+= get(1,0,n,l,r);
	}
	cout<<ans;
}