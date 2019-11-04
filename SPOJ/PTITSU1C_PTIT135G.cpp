#include<iostream>
using namespace std;
void Sapxep(int a[], int n)
{
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		 if(a[i]>a[j])
		 {
		 	long tam;
		 	tam=a[i];
		 	a[i]=a[j];
		 	a[j]=tam;
		 }
	}
}
int main()
{
		int n,m,i,j,k,max;
		cin>>n>>m;
		int a[n];
		for (i=0;i<n;i++) cin>>a[i];
		Sapxep(a,n);
		max=a[0]+a[1]+a[2];
		for (i=0;i<n-2;i++)
		  for (j=i+1;j<n-1;j++)
		    for (k=j+1;k<n;k++)
		    {
		    	if(a[i]+a[j]+a[k]<=m && a[i]+a[k]+a[j]>=max) max=a[i]+a[j]+a[k];
			}
		cout<<max<<endl;
		return 0;
}
