#include<iostream>
using namespace std;
int main()
{
	string s,b;
	b="";
	cin>>s;
	int t=s.length(),i,vitri;
	bool flag=false;
	for (i=0;i<t;i++)
	{
		if(s[i]=='0')
		{
			flag=true;
			vitri=i;
			break;
		}
	}
	if(flag==true)
	{
		for (i=0;i<vitri;i++) b+=s[i];
	for (i=vitri+1;i<t;i++) b+=s[i];
	}
	else for (i=0;i<t-1;i++) b+=s[i];
	cout<<b;
	return 0;
}
