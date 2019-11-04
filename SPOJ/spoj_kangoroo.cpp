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
long min2(long a,long b, long c)
{
	return min1(min1(a,b),c);
}
long max2(long a,long b, long c)
{
	return max1(max1(a,b),c);
}
long trungbinh1(long a, long b, long c)
{
	if(a!=max2(a,b,c) && a!=min2(a,b,c)) return a;
		else if(b!=max2(a,b,c) && b!=min2(a,b,c)) return b;
		  else return c;
}
int main()
{
	long a,b,c,dem=0,max,min,trungbinh;
	cin>>a>>b>>c;
    max=max2(a,b,c);
    min=min2(a,b,c);
    trungbinh=trungbinh1(a,b,c);
	while ((max-trungbinh)%2==0||(trungbinh-min)%2==0||((max-trungbinh)%2==0&&(trungbinh-min)%2==0))
	{
		if((max-trungbinh)%2==0 &&(max-trungbinh)>(trungbinh-min))
			{
				min=(max-trungbinh)/2;
				dem++;
			}
		else if((trungbinh-min)%2==0&&(trungbinh-min)>(max-trungbinh))
		   {
		   	max=(trungbinh-min)/2;
		   	dem++;
		   }
		min=min2(min,max,trungbinh);
		max=max2(min,max,trungbinh);
		trungbinh=trungbinh1(min,max,trungbinh);
	}
	cout<<dem;
}
