#include<iostream>
#include<math.h>
using namespace std;
long kt(int n)
{
	if(int(n)==n) return 1;else return 0;
}
int Kiemtraluythua(int n, int m)
{
	float k;
	k=log(n)/log(m);
	if(int(k)==k) return 1;else return 0;
}
int main()
{
	int l,r,x,i,flag=0;
	cin>>l; cin>>r; cin>>x;
	float a,b;
	a=int(float(log(l))/log(x));
	b=int(float(log(r))/log(x));
	for (i=a;i<=b;i++)
	{
		if(Kiemtraluythua(i,x)==1) 
		{
			cout<<i<<" ";
			flag=1;
		}
	}
	if(flag==0) cout<<" -1 "<<endl;
}
