#include<bits/stdc++.h>

using namespace std;

void trunghieu()
{
	string s;
	map<string,int> cnt;
	while(getline(cin,s))
	{
		if(s == "")
			break;
		stringstream ss(s);
		string token;
		while(ss>>token)
			cnt[token]++;
	}
	cout<<cnt.size()<<endl;
	for(auto i:cnt)
		cout<<i.first<<" "<<i.second<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	trunghieu();
	return 0;
}