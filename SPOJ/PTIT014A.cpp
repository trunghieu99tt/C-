#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for (int i=0;i<=t;i++)
	{
		char s[8];
	     gets(s);
	      char a[]="dung", b[]="lon hon", c[]="nho hon";
	     if(strstr(s,a)) cout<<"2"<<endl;
	       else if(strstr(s,b)) cout<<"1"<<endl;
	         else if(strstr(s,c)) cout<<"3"<<endl;
	}
	return 0;
}
