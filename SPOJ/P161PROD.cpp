#include<iostream>
using namespace std;
int kt(char a, string b)
{
	bool flag=false;
	for (int i=0;i<b.length();i++)
	{
		if(b[i]==a) 
		{
			flag=true;
			break;
		}
	}
	if(flag==true) return 1; else return 0;
}
int vitri(char a, string b)
{
	bool flag=false;
	int vitri;
	for (int i=0;i<b.length();i++)
	{
		if(b[i]==a) 
		{
			flag=true;
			vitri=i;
			break;
		}
	}
	return vitri;
}
int main()
{
		string d1="qwertyuiop",d2="asdfghjkl;",d3="zxcvbnm,./";
	int t1=d1.length(),t2=d2.length(),t3=d3.length();
	char a;
	cin>>a;
	string s;
	cin>>s;
	int i,l;
	l=s.length();
	if(a=='R')
	{
		for (i=0;i<l;i++)
		  {
		  	if(s[i]!=d1[0] && s[i]!=d2[0] && s[i]!=d3[0])
		  	{
		  		if(kt(s[i],d1)==1)
		  		{
		  			int k=vitri(s[i],d1);
		  			s[i]=d1[k-1];
				}
				else if((kt(s[i],d2)==1))
				{
					int k=vitri(s[i],d2);
		  			s[i]=d2[k-1];
				}
				else if((kt(s[i],d3)==1))
				{
					int k=vitri(s[i],d3);
		  			s[i]=d3[k-1];
				}
			  }
		  }
	}
	else
	{
		for (i=0;i<l;i++)
		  {
		  	if(s[i]!=d1[t1] && s[i]!=d2[t1] && s[i]!=d3[t3])
		  	{
		  		if(kt(s[i],d1)==1)
		  		{
		  			int k=vitri(s[i],d1);
		  			s[i]=d1[k+1];
				}
				else if((kt(s[i],d2)==1))
				{
					int k=vitri(s[i],d2);
		  			s[i]=d2[k+1];
				}
				else if((kt(s[i],d3)==1))
				{
					int k=vitri(s[i],d3);
		  			s[i]=d3[k+1];
				}
			  }
		  }
	}
		for (i=0;i<l;i++) cout<<s[i];
   return 0;
}
