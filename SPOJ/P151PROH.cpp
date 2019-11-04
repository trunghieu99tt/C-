#include<iostream>
using namespace std;
int sochuso(long n)
{
	int dem=0;
	while(n>0)
	{
		dem++;
		n/=10;
	}
	return dem;
}
void numbertoarray(long n, int a[])
{
	int i=1;
	while(n>0)
	{
		a[i]=n%10;
		n/=10;
		i++;
	}
}
int main()
{
		long n,i,k;
	cin>>n;
	k=sochuso(n);
	int a[k];
	numbertoarray(n,a);
	if(a[k]==4 || (a[k]==4 && a[k-1]==4)) cout<<"NO";
	else
	{
		bool flag=true;
	for (i=k;i>=1;i--) 
	 if(a[i]!=1 && a[i]!=4)
	 {
	 	flag=false;
	 	cout<<"NO";
	 	break;
	 }
	if(flag==true)
	{
		bool flag1=true;
		for (i=k;i>=3;i--)
		{
			if(a[i]==4 && a[i-1]!=1 && a[i-2]!=1)
			   {
			   	flag1=false;
					cout<<"NO";
					break;
				}
		}
		if(flag1==true) cout<<"YES";
	}
	}
	return 0;
}
