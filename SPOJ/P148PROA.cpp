#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==0) break;
		else if(n==1) cout<<1<<endl;
		else 
		{
			int dem=1;
			while(n!=1)
	        {
		         dem++;
		        if(n%2==0) n/=2;
		        else n=n*3+1;
	        }
	        cout<<dem<<endl;
		};
	}
	return 0;
}
