#include<iostream>
using namespace std;
string chuanhoa(string s)
{
	string b;
	b="";
	for (int i=0;i<s.length();i++)
	 if(s[i]!='0') b+=s[i];
	return b;
}
int kt(string s[], int n)
{
	bool flag=false;
	for (int i=0;i<n;i++)
	{
		if(s[i]!=s[0]) 
		{
			flag=true;
			break;
		}
	}
	if(flag==true) return 1; else return 0;
}
int main()
{
	int k=1;
	while(1)
	{
		int n,lenmax;
		cin>>n;
		if(n==0) return 0;
		string s[n],max,min;
		for (int i=0;i<n;i++) cin>>s[i];
		if(kt(s,n)==0) cout<<"Case "<<k<<": "<<"There is a row of trees having equal height."<<endl;
		else
		{
			lenmax=s[0].length();
		for (int i=1;i<n;i++)
		{
			if(s[i].length()>=lenmax) lenmax=s[i].length();
		}
		for(int i=0;i<n;i++)
		{
			if(s[i].length()<lenmax)
			{
				while(s[i].length()!=lenmax) s[i]='0'+s[i];
			}
		}
	    max=s[0], min=s[0];
	    for (int i=1;i<n;i++)
	    {
	    	if(s[i]>=max) max=s[i]; 
	    	else if(s[i]<=min) min=s[i];
		}
		max=chuanhoa(max);
		min=chuanhoa(min);
		cout<<"Case "<<k<<": "<<min<<" "<<max<<endl;
		}
		k++;
	}
	return 0;
}
