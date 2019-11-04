#include<iostream>
using namespace std;
int kt(string s)
{
	int i;
	for (i=0;i<s.length();i++)
	{
		 if(s[i]=='0') return 0;
	}
	return 1;
}
int main()
{
	int n,i;
	cin>>n;
	string s="";
	for (i=0;i<n;i++) s+='0';
	cout<<s<<endl;
	while(kt(s)!=1)
	{
		for (i=s.length()-1;i>=0;i--)
		{
			 if(s[i]==0)
		   {
		 	 if(i==s.length()-1) 
		 	 {
		 	 	s[i]='1';
		 	 cout<<s;
			  }
			  else
			  {
			  	s[i]='1';
			  	for (int j=i+1;j<s.length();j++) s[j]='0';
			  	cout<<s;
			  }
		    } 
		}
	}
	cout<<s<<endl;
}

