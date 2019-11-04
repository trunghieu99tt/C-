#include<iostream>
using namespace std;
int max(int a[])
{
	int i,max=a[0];
	for (i=1;i<9;i++) if(a[i]>=max) max=a[i];
	return max;
}
int min(int a[])
{
	int i,min=a[0];
	for (i=1;i<9;i++) if(a[i]<=min) min=a[i];
	return min;
}
int main()
{
	int A,B,C;
	cin>>A>>B>>C;
	int a[6], max1,i,l,j=0,dem=1,min1;
	for (i=0;i<6;i++) cin>>a[i];
	max1=max(a);
	min1=min(a);
	l=max1-min1;
	int b[l+1],c[l+1],d[3];
	for (i=1;i<=3;i++) d[i]=0;
	for (i=min1;i<=max1;i++) b[i]=0;
	for (i=a[0];i<=a[1]+1;i++)b[i]++;
	for (i=a[2]+1;i<=a[3]+1;i++) b[i]++;
	for (i=a[4]+1;i<=a[5];i++) b[i]++;
	c[0]=b[min1];
	for (i=min1+1;i<=max1;i++)
	{
		if(b[i]!=b[i-1]) 
		{
			c[++j]=b[i];
			dem++;
		}
	}
	for (i=min1;i<=max1;i++) cout<<b[i]<<" ";
	cout<<endl;
	for (i=0;i<dem;i++) cout<<c[i]<<" ";
	cout<<endl;
	j=min1;
	for (i=0;i<dem;i++)
	{
		int dem1=0;
		while(b[j]==c[i])
			{
				dem1++;
				j++;
			}
		cout<<dem1<<endl;
		for (int m=1;m<=3;m++)
			 if(c[i]==m) 
			 {
			 	if(dem1<=2)
			 	d[m]+=dem1;
			 	else d[m]+=(dem1-1);
			 	break;
	        }
	}
	for (i=1;i<=3;i++) cout<<d[i]<<" ";
	cout<<endl;
	cout<<d[1]*A+d[2]*B*2+d[3]*C*3;
	return 0;
 }
