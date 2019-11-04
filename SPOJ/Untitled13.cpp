#include<iostream>
using namespace std;
string numbertostring (long long n)
{
	string s="";
	int i=0;
	while(n>0)
	{
		s+=(n%10+48);
		i++;
		n/=10;
	}
	return s;
}
int main()
{
	string s;
	cin>>s;
	long long kq=0,i;
	for (i=0;i<s.length();i++) kq+=(s[i]-48);
	cout<<kq;
	s=numbertostring(kq);
	cout<<s;
	return 0;
}
