#include<iostream>
using namespace std;
int kt(string s)
{
	int dem1=0,dem2=0,dem3=0;
	for (int i=0;i<s.length();i++) 
	{
		if(s[i]>='a' && s[i]<='z') dem1++;
		else if(s[i]>='A' && s[i]<='Z') dem2++;
		else if((s[i]-'0')>=0 && (s[i]-'0')<=9) dem3++;
	}
	if(dem1>0 && dem2>0 && dem3>0) return 1; else return 0;
}
int main()
{
	string s;
	cin>>s;
	int i,n=s.length(),dem=0,j;
    for (i=0;i<n-6;i++)
    {
    	string b="";
    	for (j=i;j<n;j++) 
    	{
    		b+=s[j];
    		if(b.length()>=6 && kt(b)==1) dem++;
    	}
    }
    cout<<dem;
    return 0;
}
