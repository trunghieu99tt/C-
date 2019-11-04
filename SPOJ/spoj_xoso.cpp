#include<iostream>
using namespace std;
long dem(int a[], long n,int m)
{
	long dem=0;
	for (long i=0;i<n;i++)
	 if(a[i]==m) dem++;
	 return dem;
}
int main()
{
   long n,x,vitri,somin,i,j,k,min,dem1=1,flag,f;
   cin>>n>>x;
   int a[n],b[100000];
   for ( i=0;i<n;i++) cin>>a[i];
     k=0;
    b[0]=a[0];
	for ( i=1;i<n;i++)
	{
        flag=1;
		for ( j=i-1;j>=0;j--)
		  if(a[i]==a[j]) flag=0;
		if(flag==1) 
		{
			b[++k]=a[i];
			dem1++;
		}
	}
	min=dem(a,n,b[0]);
	for ( j=1;j<dem1;j++)
	  if(dem(a,n,b[j])<=min) min=dem(a,n,b[j]);
	for (j=0;j<dem1;j++)
	  if(dem(a,n,b[j])==min) 
	  {
	  	 somin=b[j];
	  	 vitri=j;
	     break;
	  }
	for ( f=vitri+1;f<dem1;f++)
	{
		if((dem(a,n,b[f])==min) && (b[f]>=somin)) somin=b[f];
	}
	cout<<n*x-somin*min;
	return 0;
}
