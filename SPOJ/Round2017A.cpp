#include<iostream>
#include<math.h>
using namespace std;
int sochinhphuong(int n)
{
	if (int(sqrt(n))==sqrt(n)) return 1; else return 0;
}
int main()
{
	int t,x[100],i,j,dem;
	cin>>t;
	for (i=0;i<t;i++)
	 cin>>x[i];
	for (i=0;i<t;i++)
     {
     	dem=0;
     	for (j=0;j<=x[i]/2;  j++)
     	 if(sochinhphuong(j)==1&& sochinhphuong(x[i]-j)==1) dem++;
     	cout<<dem<<endl;
	 }
	return 0;
}
