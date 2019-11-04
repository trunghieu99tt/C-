#include<iostream>
using namespace std;
int main()
{
	int n,i;
	bool flag;
	cin>>n;
	string a[n],b,c;
	for(i=0;i<n;i++) 
	 cin>>a[i];
	b=a[0];
	for (i=1;i<n;i++)
	{
		if(a[i]!=b) 
		{
			flag=true;
			c=a[i];
			break;
		}
		else flag=false;
	}
	if(flag==false ) cout<<b;
	else
	{
		int dem=0,dem1=0;
		for (i=0;i<n;i++)
		{
			if(a[i]==b) dem++; else if(a[i]==c) dem1++;
		}
		if(dem>dem1) cout<<b; else cout<<c;
	}
	return 0;
}
