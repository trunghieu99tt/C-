#include<iostream>
using namespace std;
int main()
{
	int n,f;
	cin>>n;
	for (f=0;f<n;f++)
	{
		int n,i=0,dem=0;
		cin>>n;
		int a[]={500,200,100,50,20,10,5,2,1};
		while(n>0)
        {
			if(n>=a[i])
			 {
			 	int t=n/a[i];
			 	dem+=n/a[i];
			 	n-=t*a[i];
			 	i++;
			 }
			 else i++;
		}
		cout<<dem<<endl;
	}
	return 0;
}
