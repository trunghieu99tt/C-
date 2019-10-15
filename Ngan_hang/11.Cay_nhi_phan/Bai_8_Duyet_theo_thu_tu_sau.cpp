#include<bits/stdc++.h>

using namespace std;

int find(int pre[], int n){
	for(int i = 1;i<n;i++)
		if(pre[i] > pre[0])
			return i;
	return n;
}

void solve(int pre[], int n){
	if(n > 1)
	{
		int pos = find(pre,n);
		solve(pre+1,pos-1);
		solve(pre + pos, n - pos);
	}
	if(n > 0)
		cout<<pre[0]<<" ";
}

void solve()
{
	int t;
	cin>>t;
	cout<<t<<endl;
	while(t--)
	{
		int n;
		cin>>n;
		int pre[n],i;
		for(i = 0;i<n;i++)
			cin>>pre[i];
		solve(pre,n);
		cout<<endl;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	solve();
	return 0;
}