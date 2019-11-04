#include<iostream>
using namespace std;
string tong(string s)
{
	string res="";
	int x=0;
	for (int i=0;i<s.length();i++)
		x+=s[i]-'0';
	while(x>0)
	{
		res+=(x%10)+'0';
		x/=10;
	}
	return res;
}
int main()
{
	string s;
	int count =0;
	cin>>s;
	while(s.length()>1)
	{
		count++;
		s=tong(s);
	}
	cout<<count<<endl;
	return 0;
}
