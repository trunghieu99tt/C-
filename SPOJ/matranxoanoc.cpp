#include<iostream>
using namespace std;
void Nhapmang(int a[][100],int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
}
void Chuyenmang(int a[][100], int b[], int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			b[i+j]=a[i][j];
		}
	}
}
void Sapxepmang(int a[], int n)
{
	for (int i=0;i<n*n-1;i++)
	{
		for (int j=i+1;j<n*n;j++)
		 if(a[i]>a[j])
		 {
		 	int tam;
		 	tam=a[i];
		 	a[i]=a[j];
		 	a[j]=tam;
		 }
	}
}
void Chuyenmatran(int a[], int b[][100], int n)
{
	int i=0,j=0,k,l=0,tam;
	while(i<n*n)
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
void Xuatmatran(int a[][100], int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
int main()
{
	int n,a[10000],b[100][100];
	cin>>n;
	Nhapmang(b,n);
	Chuyenmang(b,a,n);
	Sapxepmang(a,n);
	Chuyenmatran(a,b,n);
	Xuatmatran(b,n);
	return 0;
}
