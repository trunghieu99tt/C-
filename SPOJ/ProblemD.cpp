#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
int a[123],i;
void Init(int a[])
{
	for (i=65;i<=90;i++)
		a[i]=i-65;
}
char returnchar(char s,int n)
{
	int index=a[s],k=index+n;
	k%=26;
	return char(k+65);
}
int main()
{
	Init(a);
	// for (i=65;i<=90;i++) 
	// 	cout<<a[i]<<" ";
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		string s;
		cin>>s;
		int sum1=0,sum2=0,sum3=0;
		string s1="",s2="";
		for (i=0;i<s.length()/2;i++)
			{
				sum1+=a[s[i]];
				s1+=s[i];
			}
		for (i=s.length()/2;i<s.length();i++)
			{
				sum2+=a[s[i]];
				s2+=s[i];
			}
		// cout<<s1<<" "<<s2<<endl;
		// cout<<sum1<<" "<<sum2<<endl;
		for (i=0;i<s1.length();i++)
			s1[i]=returnchar(s1[i],sum1);
		for (i=0;i<s2.length();i++)
			s2[i]=returnchar(s2[i],sum2);
		// cout<<s1<<" "<<s2<<endl;
		for (i=0;i<s1.length();i++)
		{
			s1[i]=returnchar(s1[i],a[s2[i]]);
		}
		cout<<s1<<endl;
	}
	return 0;
}