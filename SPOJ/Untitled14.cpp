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
string xuli(string s)
{
	string b;
	long long kq=0,i;
	if(s[0]=='-') 
	{
		kq-=(s[1]-48);
	    for (i=2;i<s.length();i++)  kq+=(s[i]-48);
	}
	else 
	{
		for (i=0;i<s.length();i++) kq+=(s[i]-48);
	}
	b=numbertostring(kq);
	return b;
}
int main()
{
	string s;
	cin>>s;
	int dem=0;
	while(s.length()!=1)
	{
		s=xuli(s);
		dem++;
		if(s.length()==1) break;
		if(s=="01") break; 
	}
	cout<<dem;
}
