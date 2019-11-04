#include<iostream>
using namespace std;
long minmang(long a[],long n)
{
	long min;
	min=a[0];
	for (long i=1;i<n;i++) if(a[i]<min) min=a[i];
	return min;
}
long maxmang(long a[], long n)
{
	long max;
	max=a[0];
	for (long i=1;i<n;i++) if(a[i]>max) max=a[i];
	return max;
}
long kt(long n)
{
	if((n%4==0 && n%100!=0)||(n%400==0)) return 1; else return 0;
}
long songay(long th,long nam)
{
	long songay;
	switch(th)
	{
		case 1: case 3:case 5: case 7:case 8: case 10:case 12: songay=31;break;
		case 4:case 6:case 9:case 11: songay=30;break;
		case 2:if(kt(nam)==1) songay=29; else songay=28;break;
		default: cout<<"khong co thang nay, yeu cau nhap lai...";
	}
	return songay;
}
long tong(long a, long b,long c)
{
	long kq=0;
	for (long i=1;i<b;i++) kq+=songay(i,c);
	kq+=a;
	return kq;
}
int main()
{
	long n,i,min,max,minnam,maxnam,vitrimin1, vitrimax1,j,maxngay,minngay,k,tenmax,tenmin;
	cin>>n;
	char ten[n+1][16];
	long a[n],b[n],c[n];
	for (i=0;i<n;i++)
	{
		cin>>ten[i];
		cin>>a[i]>>b[i]>>c[i];
	}
	maxnam=maxmang(c,n);
	minnam=minmang(c,n);
	for (i=0;i<n;i++)
		if(c[i]==maxnam)
		{
			maxngay=tong(a[i],b[i],c[i]);
			vitrimax1=i;
			break;
		}
	for (i=0;i<n;i++)
	   if(c[i]==minnam)
	   {
	   	
			minngay=tong(a[i],b[i],c[i]);
			vitrimin1=i;
			break;
		}
    for (j=vitrimax1;j<n;j++)
      {
      	if(c[j]==maxnam)
      {
      	  if(tong(a[j],b[j],c[j])>=maxngay) 
      	{
      	  	maxngay=tong(a[j],b[j],c[j]);
      	  	tenmin=j;
		}
	  }
	  }
	for (k=vitrimin1;k<n;k++)
	  if(c[k]==minnam)
	  {
	  	if(tong(a[k],b[k],c[k])<=minngay) 
      	{
      	  	minngay=tong(a[k],b[k],c[k]);
      	  	tenmax=k;
		}
	  }
	cout<<ten[tenmin]<<endl;
	cout<<ten[tenmax]<<endl;
	return 0;
}
