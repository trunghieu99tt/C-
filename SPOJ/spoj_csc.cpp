#include<iostream>
using namespace std;
long max1(long a, long b)
{
	if (a>b) return a; else return b;
}
long min1(long a, long b)
{
	if (a>b) return b; else return a;
}
int main()
{
	long a,b,c,max,min,trungbinh,csc;
	cin>>a>>b>>c;
	max=max1(max1(a,b),c); 
	min=min1(min1(a,b),c); 
	if(a!=max && a!=min) trungbinh=a;
		else if(b!=max && b!=min) trungbinh=b;
		  else trungbinh=c;
	if(max-trungbinh>=trungbinh-min) csc=trungbinh-min; else csc=max-trungbinh;
	if(max-trungbinh==csc && trungbinh-min==csc) cout<<max+csc;
	else if(max-trungbinh==csc && trungbinh-min>csc) cout<<min+csc;
	else if(max-trungbinh>csc && trungbinh-min==csc) cout<<trungbinh+csc;
	return 0;
}
