#include<iostream>
#include<math.h>
using namespace std;
int sochuso(long x)
{
	int dem=0;
	while(x>0)
	{
		dem++;
		x/=10;
	}
	return dem;
}
void numbertoarray(int a[], long x)
{
	for (int i=1;i<=sochuso(x),x>0;i++)
	{
		a[i]=x%10;
		x/=10;
	}
}
int main()
{
	int t;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		long x,tam;
		cin>>x;
		int n;
		n=sochuso(x);
		int k=pow(10,n-1);
		if(n==1) cout<<x<<endl;
		else if(n==2) 
		{
			if(x%10>=5) cout<<(x/10+1)*10<<endl; else cout<<(x/10)*10<<endl;
		}
		else
		{
	    if(x==(x/k)*k) cout<<x<<endl;
	    else
		{
		tam=x;
		int a[100];
		numbertoarray(a,x);
		for (int j=1;j<=n-1;j++)
		{
			if(a[j]>=5) a[j+1]+=1;
		}
		if(a[n-1]>=5) tam=(tam/k+1)*k; else tam=(tam/k)*k;
		cout<<tam<<endl;
		}
		}
	}
	return 0;
}
