#include<iostream>
#include<math.h>
using namespace std;
int sochuso(int n)
{
	int dem=0;
	while(n>0)
	{
		dem++;
		n/=10;
	}
	return dem;
}
Sapxepmang(int a[], int n)
{
	for (int i=0;i<n;i++)
	   {
	   	  for (int j=i+1;j<n;j++)
	   	     if(a[i]>a[j])
	   	     {
	   	     	int tam=a[i];
	   	     	a[i]=a[j];
	   	     	a[j]=tam;
				}
	   }
}
void Numbertoarray(int a, int n, int b[])
{
	for (int i=0;i<n;i++)
	{
		b[i]=a%10;
		a/=10;
		cout<<a<<endl;
	}
	
}
int  Arraytonumber(int a, int n, int b[])
{
	for (int i=1;i<n;i++)
	 a=b[i]*pow(10,sochuso(b[i-1]));
	return a+b[0];
}
int main()
{
	int t,n[100],a[100],b[100],i,j,k,m;
	cin>>t;cout<<endl;
	for (i=0;i<t;i++)
		{
			cin>>n[i]; cin>>a[i]; cout<<endl;
		}
	for (i=0;i<t;i++)
	{
		  k=n[i];
	     Numbertoarray(a[i],n[i],b);
	     for (j=0;j<sochuso(a[i]);j++)
	     {
	     	switch(b[j])
	     	{
	     		case 1: b[j]=1;break;
	     		case 2: b[j]=21;break;
	     		case 3: b[j]=31;break;
	     		case 4: b[j]=3221;break;
	     		case 5: b[j]=51;break;
	     		case 6: b[j]=531;break;
	     		case 7: b[j]=71;break;
	     		case 8: b[j]=7221;break;
	     		case 9: b[i]=91; break;
			 }
		 }
		 Arraytonumber(a[i],k,b);
		 m=sochuso(a[i]);
		 Sapxepmang(b,m);
		 Numbertoarray(a[i],m,b);
		 Arraytonumber(a[i],k,b);
		 cout<<a[i]<<endl;
	}
}
