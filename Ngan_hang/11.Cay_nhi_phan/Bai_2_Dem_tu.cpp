#include<bits/stdc++.h>

using namespace std;

void solve()
{
	string s;
	map<string,int> cnt;
	while(cin>>s)
		cnt[s]++;
	cout<<cnt.size()<<endl;
	for(auto i:cnt)
		cout<<i.first<<" "<<i.second<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}