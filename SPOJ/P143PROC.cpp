#include<iostream>
using namespace std;
int kt(float a)
{
	if(int(a)==a) return 1; else return 0;
}
int main()
{
		long long n,k,l,y,i;
	cin>>y>>k>>n;
	if (kt(float(y+1)/k)==1) i=(y+1)/k; else i=int((y+1)/k)+1;
	if(i > n/k) cout<<"-1";
	else 
	{
		for (l=i; l<= int(n/k);l++)
	  {
	  	if((k*l-y)>=1 ) cout<<(k*l-y)<<" "; else 
		  {
		  	cout<<"-1";
		  	break;
		  }
	  }
	}
	return 0;
}
