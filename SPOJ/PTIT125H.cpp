#include<iostream>
using namespace std;
int kt1(string s)
{
	for (int i=0;i<s.length();i++) if(s[i]!='S') return 1;
	return 0;
}
int kt2(string s)
{
	for (int i=0;i<s.length();i++) if(s[i]!='L') return 1; 
	return 0;
}
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	string b="*";
	int i=0,dem=0;
	while(i<s.length())
	 {
	 	if(s[i]=='S') 
	 	{
	 		b=b+s[i]+'*';
	 		i++;
	 	}
	     else 
	     {
	     	b=b+s[i]+s[i]+'*';
	     	i+=2;
	     }
	 }
	for (i=0;i<b.length();i++) if(b[i]=='*') dem++;
	if(kt1(s)==0) cout<<dem-1;
	else if(kt2(s)==0) cout<<2; 
	else cout<<dem;
	return 0;
}
