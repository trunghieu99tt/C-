#include<iostream>
using namespace std;
int main()
{
	int t,k;
	cin>>t;
	for (k=0;k<t;k++)
	{
		long n,a,b,i,j,min;
	bool flag=false;
	cin>>n>>a>>b;
	min=a;
	for (i=0;i<=n/a;i++)
	  for (j=0;j<=n/b;j++)
	  {
	  	if(i*a+j*b==n && i+j<=min) 
	  	{
	  		min=i+j;
	  		flag=true;
		  }
	  }
	if(flag==false) cout<<"-1"<<endl;
	else cout<<min<<endl;
	}
}
