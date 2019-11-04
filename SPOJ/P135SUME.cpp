#include<iostream>
using namespace std;
int main()
{
	int a[8],i,j,dem=0,dem1=0;
	for ( i=0;i<8;i++) cin>>a[i];
	for (i=0;i<7;i++) 
	  {
	  	if(a[i]<a[i+1]) dem++;
	  	else dem1++;
	  }
	if(dem==7) cout<<"ascending";
	else if(dem1==7) cout<<"descending";
	else cout<<"mixed";
	return 0;
}
