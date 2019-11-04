#include<iostream>
using namespace std;
int main()
{
	int i,j,a[24][61],n,dem=0,x,y;
	cin>>n;
	for (i=0;i<=23;i++)
	{
		for (j=0;j<=59;j++)
		  a[i][j]=0;
	}
	for (i=0;i<n;i++)
	 {
	 	cin>>x>>y;
	 	a[x][y]++;
	 	if(dem<=a[x][y]) dem=a[x][y];
	 }
	cout<<dem;
}
