#include<iostream>
#include<math.h>
using namespace std;
int main()
{
		int k,dem=0,kq=0,n,l,tam;
	cin>>k;
	n=(log(k)/log(2))+1;
	l=pow(2,n);
	tam=l;
	while(kq!=k,l>0)
	{
		if(kq==k) break;
		if( kq+l/2 <=k) 
		{
			kq+=l/2;
		}
		l=l/2;
		dem++;
	}
	if(dem==1) cout<<tam/2<<" "<<0;
	else
	cout<<tam<<" "<<dem;
	return 0;
}

