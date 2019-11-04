#include<iostream>
using namespace std;
int kt(char s)
{
	if(s!='a'&& s!='o'&& s!='y'&&s!='e'&&s!='u'&&s!='i') return 1;else return 0;
}
int main()
{
		string s,b="";
	cin>>s;
	int i,l=s.length(),dem=0;
	if(l==1 && kt(s[0])==0) cout<<" ";
	else
	{
		for (i=0;i<l;i++) 
	    {
	    	if(s[i]!=' ' && s[i]>=65 && s[i]<=90) s[i]+=32;  
		}
	for (i=0;i<l;i++)
	{
		if(kt(s[i])==1)
		{
			 b+=s[i];
			 dem++;
		}
	}
	for (i=0;i<dem-1;i++) cout<<"."<<b[i];
	cout<<"."<<b[dem-1];
	}
	return 0;
}
