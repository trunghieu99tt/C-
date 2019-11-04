#include<iostream>
using namespace std;
int main()
{
	int a[100],i,dem=0;
	bool flag=false;
	for (i=65;i<=90;i++) a[i]=0;
	string s,b;
	cin>>s>>b;
	for (i=0;i<s.length();i++) a[s[i]]++;
	for (i=0;i<b.length();i++) a[b[i]]++;
	for (i=65;i<=90;i++) 
	{
		if(a[i]==2)
		{
			dem++;
			flag=true;
		}
		else if(a[i]==3) 
		{
			dem+=2;
			flag=true;
		}
	}
	if(flag==false) cout<<s.length()+b.length();
	else cout<<s.length()+b.length()-dem;
}
