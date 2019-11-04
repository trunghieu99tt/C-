#include<iostream>
using namespace std;
int dem(int a[], int n, int m)
{
	int dem=0;
	for (int i=0;i<n;i++)
	  if(a[i]==m) dem++;
	  return dem;
}
void yeucau(int a[], int b[], int n)
{
	int k=1,dem1=1,i,j,max,somin,vitri;
	b[0]=a[0];
	for (i=1;i<n;i++)
	{
		bool flag=true;
		for (j=i-1;j>=0;j--)
		  if(a[i]==a[j]) flag=false;
		if(flag==true)
		{
			b[k]=a[i];
			k++;
			dem1++;
		}
	}
    max=dem(a,n,b[0]);
    for (j=1;j<dem1;j++) 
    	if(dem(a,n,b[j])>max) max=dem(a,n,b[j]);
	for (i=0;i<dem1;i++)
	   {
	   	if(dem(a,n,b[i])==max) 
	   	{
	   		somin=b[i];
	   		vitri=i;
	   		break;
		   }
	   }
	for (i=vitri;i<dem1;i++)
	{
		if(dem(a,n,b[i])==max&& b[i]<=somin) somin=b[i];
	}
	cout<<somin<<endl;
}
int main()
{
	int t;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int a[n],b[n],j;
		for(j=0;j<n;j++) cin>>a[j];
		yeucau(a,b,n);
	}
	return 0;
}
