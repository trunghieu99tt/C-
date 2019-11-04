#include<iostream>
#include<string.h>
using namespace std;
int kt(char s[])
{
	int k=strlen(s);
	for (int i=0;i<k;i++)
	{
		 if(s[i]!=s[k-i-1]) return 0;
	}
	return 1;
}
int main()
{
	int t;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		char s[21];
		cin>>s;
		if(kt(s)==1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	}
	return 0;
}
