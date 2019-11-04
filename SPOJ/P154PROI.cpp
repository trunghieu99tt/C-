#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int t,k;
	cin>>t;
	cin.ignore();
	for (k=0;k<t;k++)
	{
		char s[100000],r[100000];
		bool flag=true;
		int i;
		gets(s);
		for (i=strlen(s)-1;i>=0;i--) r[strlen(s)-i-1]=s[i];
		for (i=1;i<strlen(s);i++) 
		{
			if(abs(s[i]-s[i-1])!=abs(r[i]-r[i-1]))
			{
				flag=false;
				break;
			}
		}
		if(flag==true) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	}
	return 0;
}
