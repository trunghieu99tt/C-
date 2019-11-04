#include<iostream>
using namespace std;
void mangtich(long b[], long a[][&m],long n,long m)
{
	for (long j=0;j<m;j++)
	{
		long kq=1;
		for (long i=0;i<n;i++)
		  kq*=a[i][j];
		b[j]=kq;
		cout<<b[j]<<" ";
	}
}
void vitrimax(long b[], long m )
{
	long max,i,vitrimax;
	max=b[0];
	for (i=0;i<m;i++)
	 if(b[i]>=max)
	 {
	 	max=b[i];
	 	vitrimax=i;
	 }
	cout<<vitrimax<<endl;
}
int main()
{
	while(1)
	{
		long n,m,j,k;
		cin>>n; cin>>m;
		if (n==0 && m==0) break; 
		else 
		{
			long a[n][m],b[m];
		for (j=0;j<n;j++)
		{
			for (k=0;k<m;k++)
			  cin>>a[j][k];
			cout<<endl;
		}
	mangtich(b,a,n,m);
	vitrimax(b,m);	
	  }
    }
    
   return 0;		
}
