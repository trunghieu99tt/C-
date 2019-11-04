#include<iostream>
using namespace std;
int main()
{
	string s,c="",d="";
	cin>>s;
	int i,l=s.length(),j;
	for (i=l-1;i>=0;i--)
	{
		if((l-i)%3==0) 
		{
			c=','+s[i];
			c=c;
		}
		else 
		{
			c=s[i];
			c=c;
		}
	}
	if(c[0]=',')
	{
		for (i=1;i<c.length();i++) d=c[i]+d;
	}
	else for (i=0;i<c.length();i++) d=c[i]+d;
	cout<<d;
}
