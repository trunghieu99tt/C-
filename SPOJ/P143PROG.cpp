#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int j=k/(n-1);
	int du=k%(n-1);
    if(du==0) cout<<(j*n-1)<<" "<<j*n;
    else 
    {
    	int m=(j*n+du);
    	cout<<m<<" "<<m;
	}
	return 0;
}
