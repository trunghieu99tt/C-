#include<iostream>
using namespace std;
int main()
{
	long a[3],b[3],i,k,dem,flag;
	for (i=0;i<3;i++)
	  cin>>a[i]>>b[i];
	k=a[0];
	for (i=1;i<3;i++)
	 {
	 	dem=0;
	 	if(a[i]==k||b[i]==k) dem++;
	 	if(dem!=4) 
	 	{
	 		flag=0;
	 		cout<<k<<" "<<k;
		 }
		else flag=1;
	 }
    if(flag==1)
	{
		for (i=1;i<3;i++) if(a[i]!=k) 
		{
			cout<<a[i]<<" "<<a[i];
			break;
		}
    }	
    return 0;
}
