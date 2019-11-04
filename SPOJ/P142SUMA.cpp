#include<iostream>
#include<math.h>
using namespace std;
int ktsn(double n)
{
	if(int(n)==n) return 1; else return 0;
}
int main()
{
		long long n,i,l;
		cin>>n;
		if(n==1) cout<<"NO"<<endl;
		else
		{
			bool flag=false;
			l=(-2+sqrt(4+4*(8*n+1)))/4;
		    for (i=l+1;i>=0;i--)
		{
			double k;
			k=float(-1+sqrt(1-4*i*i-4*i+8*n))/2;
			if(ktsn(k)==1 && ((k*(k+1))/2+(i*(i+1))/2)==n) 
			{
				flag=true;
				break;
			}
		}
		if(flag==true) cout<<"YES"<<endl; else cout<<"NO"<<endl;
		}
		return 0;
}
