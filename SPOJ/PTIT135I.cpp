#include<iostream>
using namespace std;
int main()
{
	int t,m;
	cin>>t;
	for (m=0;m<t;m++)
	{
		string s;
	cin>>s;
	int a[10000],b[10000],c[10000],len,i,j,k=1,dem=1;
	len=s.length();
	a[0]=s[0]-48;
	for (i=1;i<len;i++)
	{
		if(s[i]!=s[i-1]) 
		{
			a[k]=s[i]-48;
			dem++;
			k++;
		}
	}
	for (i=0;i<dem;i++)b[i]=0;
	j=0;
	for (i=0;i<dem;i++)
	{
		while(s[j]-48==a[i]) 
		{
			b[i]++;
			j++;
		}
	}
	for (i=0;i<dem;i++) cout<<b[i]<<a[i];
	cout<<endl;
	}
	return 0;
}
