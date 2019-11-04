#include<iostream>
using namespace std;
int Sogannguyento(int n)
{
	int i,dem=0;
	for (i=1;i<=n;i++)
	  if(n%i==0) dem++;
	 if (dem==3) return 1; else return 0; 
}
int main()
{
	int a[100],i,n;
	cin>>n;
	for (i=0;i<n;i++)
	    cin>>a[i];
	for (i=0;i<n;i++)
		if (Sogannguyento(a[i])==1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	return 0;
}
