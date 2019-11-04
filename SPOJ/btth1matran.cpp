#include<iostream>
#include<stdlib.h>
using namespace std;
void Nhapmang(int a[],int n)
{
	for (int i=1;i<=n*n;i++) a[i]=i;
}
void Xuatmang(int a[],int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		    cout<<" "<<a[i*n+j];
		cout<<endl;
	}
}
void Sapxep(int a[],int n)
{
	int i,j,tam;
	for (i=0;i<n*n-1;i++)
	    for (j=i+1;j<n*n;j++)
	         if (a[i]>a[j])
	         {
	         	tam=a[i];
	         	a[i]=a[j];
	         	a[j]=tam;
			 }
}
void Chuyen(int a[], int b[][50], int n)
{
	int i=0,j=0,k,l=0,tam;
	   while (i<n*n)
	   {
	   	for (j=l;j<n-l;j++)
	   	     b[l][j]=a[i++];
	    for (k=l+1;k<n-l;k++)
	         b[k][n-l-1]=a[i++];
	    for (j=n-l-2;j>=l;j--)
	         b[n-l-1][j]=a[i++];
	    for (k=n-l-2;k>l;k--)
	         b[k][l]=a[i++];
	    l++;
	   }
}
void XuatMT(int a[][50], int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		   cout<<" "<<a[i][j];
		cout<<endl;
	}
}
int main()
{
	int t;
	for (int k=0;k<t;k++)
	{
		int n,a[400],b[50][50],x,y;
	cin>>n>>x>>y;
	Nhapmang(a,n);
	Xuatmang(a,n);
	Sapxep(a,n);
	Chuyen(a,b,n);
	XuatMT(b,n);
    cout<<b[x][y]<<endl;
	}
	return 0;
}
