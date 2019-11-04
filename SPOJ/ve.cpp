#include<stdio.h>
#include<math.h>
#include<string.h>
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
void numbertoarray(int n,int a[])
{
	int k=0;
	while(n>0)
	{
		a[k]=(n%10);
		n/=10;
		k++;
	}
}
int kt(int n)
{
	int a[1000];
	numbertoarray(n,a);
	int j=sochuso(n);
	int flag=1,i;
	for (i=0;i<j/2;i++) 
		{
			if(a[i]!=a[j-i-1])
			{
				flag=0;
				break;
			}
		}
	if(flag==1) return 1; else return 0;
}
int kt1(int n)
{
	int tong=0;
	while(n>0)
	{
		tong+=(n%10);
		n/=10;
	}
	if(tong%10==8) return 1; else return 0;
}
int kt3(int n)
{
	int flag=0;
	while(n>0)
	{
		int k=n%10;
		if(k==6)
		{
			flag=1;
			break;
		}
		n/=10;
	}
	if(flag==1) return 1; else return 0;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m)
	{
		int tam;
		tam=n;
		n=m;
		m=tam;
	}
	int i,dem=0;
	for (i=n;i<=m;i++) if(kt(i)==1 && kt1(i)==1 && kt3(i)==1) 
		printf("%d\n",i);
	return 0;
}