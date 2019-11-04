#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int main()
{
	int test,k;
	cin>>test;
	for (k=0;k<test;k++)
	{
		vector<char> temp;
		string a, b, c;
		cin>>a>>b>>c;
		for (auto i:a)
			temp.push_back(i);
		for (auto i:b)
			temp.push_back(i);
		for (auto i:c)
			temp.push_back(i);
		sort(temp.begin(),temp.end(),greater<char>());
		for (auto i:temp)
				cout<<i;
		cout<<endl;
	}
	return 0;
} 
