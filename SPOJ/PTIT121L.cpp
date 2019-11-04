#include<iostream>
using namespace std;
long long  maxmang(long long a[])
{
	int i,max;
	max=a[0];
	for (i=1;i<3;i++) if(a[i]>=max) max=a[i];
	return max;
}
int main()
{
	while(1)
	{
		long long a[4],b[4],max;
	int dem=0,i;
	for (i=0;i<3;i++) cin>>a[i]>>b[i];
    max=maxmang(a);
    for (i=0;i<3;i++)
    {
    	if(a[i]==max|| b[i]==max) dem++;
	}
	if(dem!=3) cout<<"0";
	else cout<<max;
	}
	return 0;
}
