#include<iostream>
using namespace std;
int Check(int a, int b, int c)
{
	if(a==b && b==c) return 1;
	return 0;
}
int main()
{
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int a[n1],b[n2],c[n3],i,tong1=0,tong2=0,tong3=0,j,k;
	for (i=0;i<n1;i++)
		{
		 cin>>a[i];
		 tong1+=a[i];
		}
	for (i=0;i<n2;i++)
		{
			 cin>>b[i];
			 tong2+=b[i];
		}
	for (i=0;i<n3;i++) 
		{
			cin>>c[i];
			tong3+=c[i];
		}
	i=0;j=0;k=0;
	while(Check(tong1,tong2,tong3)!=1)
	{
		if(tong1==max(max(tong1, tong2),tong3))
		{
			tong1-=a[i];
			i++;
		}
		else if(tong2==max(max(tong1,tong2),tong3))
		{
			tong2-=b[j];
			j++;
		}
		else
		{
			tong3-=c[k];
			k++;
		}
	}
	cout<<tong1;
}