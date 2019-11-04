#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main()
{
	char a[101],i,j;
	bool flag=true;
	gets(a);
	int n=strlen(a);
	for (i=0;i<strlen(a);i++)
	{
		if(a[i]=='[')
		 {
		 	for (j=i+1;j<n;j++) 
		 	 {
		 	 	if(a[j]==')') 
		 	 {
		 	 	flag=false;
		 	 	cout<<"no";
		 	 	break;
			  }
			else if(a[j]==']') break;
			  }
		 }
		else if(a[i]=='(')
		{
			for (j=i+1;j<n;j++)
			 {
			 	if(a[j]==']')
			 {
			 	flag=false;
			 	cout<<"no";
			 	break;
			 }
			else if(a[i]==')') break;
			 }
		}
	}
	if(flag==true) cout<<"yes";
	return 0;
}
