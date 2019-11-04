#include<iostream>
using namespace std;
int main()
{
	int a[10],i,j,dem=1,b[10];
	for (i=0;i<10;i++)
	{
		cin>>a[i];
		b[i]=a[i]%42;
	}
	for (i=1;i<10;i++)
	{
		bool flag=true;
		for (j=i-1;j>=0;j--) if(b[i]==b[j]) flag=false;
		if(flag==true) dem++; 
	}
	cout<<dem;
}
