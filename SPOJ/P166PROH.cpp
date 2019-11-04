#include<iostream>
#include<math.h>
using namespace std;
int ktnt(int n)
{
	int dem=0;
	for (int i=1;i<=sqrt(n);i++) if(n%i==0) dem++;
	if(dem==1) return 1; else return 0;
}
int kt(int n)
{
	int dem=0;
	for (int i=1;i<=n;i++) if(n%i==0 && ktnt(i)==1) dem++;
	if(dem==2) return 1; else return 0;
}
int main()
{
	while(1)
	{
		int n,dem1=0;
	cin>>n;
	for (int i=1;i<=n;i++) if(kt(i)==1) dem1++;
	cout<<dem1;
	}
	return 0;
}
