#include<iostream>
using namespace std;
int main()
{
	string s;
	int r;
	cin>>r;
	cin>>s;
	for (int i=0;i<s.length();i++)
	{
		for (int j=0;j<r;j++)
		 cout<<s[i];
	}
	return 0;
}
