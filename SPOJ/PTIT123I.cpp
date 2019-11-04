#include<iostream>
#include<math.h>
#define max 2500000
using namespace std;
int snt[max+1];
void sangnt()
{
	long i,j;
	for (i=1;i<=max;i++) snt[i]=1;
	snt[1]=0;
	i=2;
	while(i<=sqrt(max))
	{
		while(snt[i]==0) i++;
		for (j=2;j<=max/i;j++) snt[i*j]=0;
		i++;
	}
}
int main()
{
	sangnt();
	while(1)
	{
		long n;
		cin>>n;
		if(n==0) break;
		else
		{
			long dem=0;
			for (long i=n+1;i<=2*n;i++) if(snt[i]==1) dem++;
			cout<<dem<<endl;
		}
	}
	return 0;
}
