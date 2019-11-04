#include<iostream>
using namespace std;
void Doicho(long a, long b)
{
	long tam;
	tam=a;
	a=b;
	b=tam;
}
void Sapxep(long a[], long n, long b[])
{
	for (long i=0;i<n-1;i++)
	{
		for (long j=i+1;j<n;j++)
		  if(a[i]>a[j]) 
		  {
		  	Doicho(a[i],a[j]);
		  	Doicho(b[i],b[j]);
		  }
	}
}
int main()
{

	long s,n,i;
	bool flag=true;
	cin>>s>>n;
	long x[n],y[n];
	for (i=0;i<n;i++)
		cin>>x[i]>>y[i];
	Sapxep(x,n,y);
	for (i=0;i<n;i++)
	{
		if(s>x[i]) s+=y[i];
		else 
		{
			flag=false;
			break;
		}
	}
	if(flag==false) cout<<"NO";
	else cout<<"YES";
	return 0;
}
