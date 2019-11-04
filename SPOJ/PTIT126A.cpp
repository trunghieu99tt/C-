#include<iostream>
using namespace std;
void Nhapmang(int a[][20],int n, int m)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
}
void xaymang(int a[][20], int n, int m , int b[])
{
	for (int j=0;j<m;j++)
	{
		int tong=1;
		for (int i=0;i<n;i++) tong*=a[i][j];
		b[j]=tong;
	}
}
int main()
{
	while(1)
	{
		int n,m,a[1000][20],b[20],vitri,max,i;
		cin>>m>>n;
		if(n==0 && m==0) return 0;
	Nhapmang(a,n,m);
	xaymang(a,n,m,b);
	max=b[0];
	vitri=0;
	for (int i=1;i<m;i++) if(b[i]>=max) vitri=i;
	cout<<vitri+1<<endl;
	}
	return 0;
}
