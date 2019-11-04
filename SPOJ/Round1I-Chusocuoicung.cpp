#include<iostream>
#include<math.h>
using namespace std;
int Kiemtra(int n)
{
	if(n>0 && n<10) return 1; else return 0;
}
int Tongcacchuso(int n)
{
	int i,tam,dem=0,kq=0,k;
	tam=n;
	while(tam>0)
	{
		dem++;
		tam/=10;
	}
	for (i=1;i<=dem,n>0;i++)
	{
		k=pow(10,dem-i);
		kq+=n/k;
		n%=k;
	}
	return kq;
}
int main()
{
	int a[100],i,n;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>a[i]; cout<<endl;
	}
	for (i=0;i<n;i++)
	{
		if(Kiemtra(a[i])==1) cout<<a[i]<<endl;
		else 
		{
			while (Kiemtra(a[i])==0)
			{
				a[i]=Tongcacchuso(a[i]);
			}
			cout<<a[i]<<endl;
		}
	}
	return 0;
}
