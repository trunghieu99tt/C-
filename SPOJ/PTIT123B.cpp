#include<iostream>
#include<stdlib.h>
using namespace std;
int kt(long a[], int n)
{
	bool flag=true;
	for (int i=1;i<n;i++) if(a[i]!=a[0]) flag=false;
	if(flag==true) return 1; else return 0;
}
int main()
{
	int j=1;
      while(1)
      {
      	int n;
      	cin>>n;
      	if(n==0) break;
		long a[n],i,dem=0,dem1=0;
		bool flag=true;
		for (i=0;i<n;i++) cin>>a[i];
			while(kt(a,n)!=1)
			{
					long k=a[0];
				for (i=0;i<n-1;i++)
					a[i]=abs(a[i]-a[i+1]);
				a[n-1]=abs(a[n-1]-k);
				dem1++;
			    if(dem1>1000)
			    {
				flag=false;
				cout<<"Case "<<j<<" : not attained"<<endl;
				j++;
				break;
			    }
		    }
	  if(flag==true) cout<<"Case "<<j<<" : "<<dem1<<" iterations"<<endl;
	  j++;
		}
	return 0;
}
