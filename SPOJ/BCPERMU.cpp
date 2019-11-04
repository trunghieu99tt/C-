#include<iostream>
using namespace std;
int kt(int a[],int n)
{
	int i,j;
	for (i=1;i<=n-1;i++)
	  {
	  	for (j=i+1;j<=n;j++)                                 // kiem tra xem day da giam dan hay chua
	    if(a[i]<a[j]) 
	    	return 0;
	  }
	return 1;
}
int main()
{
	int n;
	cin>>n;
	int x[n],i,j,vitri,a,b;  
	for (i=1;i<=n;i++) x[i]=i;                            // thiet lap cau hinh ban dau 1,2,...,n
	for (i=1;i<=n;i++)  cout<<x[i];
	cout<<endl;
	while(kt(x,n)!=1)
	{
		i=n-1;
		while(i>0)
       {
		  	if(x[i]<x[i+1])
		   {
			for (j=n;j>=1;j--)
			 if(x[j]>x[i])
			 {
			 	swap(x[j],x[i]);
			 	break;
			 }
			 a=i+1;
			 b=n;
			 while(a<b)
			 {
			 	swap(x[a],x[b]);
			 	a++;
			 	b--;
			 }
			 for (int k=1;k<=n;k++) cout<<x[k];
			 cout<<endl;
			 break;
		   }
		else i--;
	   }
	}
}
