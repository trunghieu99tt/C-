#include<iostream>
#include<math.h>
using namespace std;
long tongchuso(long n)
{
	long i,dem=0,tam,kq=0,k;
	tam=n;
	while (tam>0)
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
long ktnam(long n)
{
	if((n%4==0 && n%100!=0)||(n%400==0)) return 1; else return 0;
}
long songaythang(long th, long nam)
{
	long songaythang;
	switch(th)
	{
		case 1:case 3:case 5: case 7: case 8:case 10:case 12: songaythang=31;break;
		case 4:case 6:case 9:case 11: songaythang=30;break;
		case 2:
			{
				if(ktnam(nam)==1) songaythang=29; else songaythang=28;
			}; break;
	}
	return songaythang;
}
long tong(long nam)
{
	long kq=0;
	for (long j=1;j<=12;j++)
		for (long i=1;i<=songaythang(j,nam);i++) kq+=tongchuso(i)+tongchuso(j);
	return kq;
}
long tongngaynam(long n)
{
	if (ktnam(n)==1) return 366; else return 365;
}
int main()
{
	long long n;
	cin>>n;
	cout<<tong(n)+tongchuso(n)*tongngaynam(n);
	return 0;
}
