#include<iostream>
#include<math.h>
using namespace std;
long kt(float n)
{
	if(int(n)==n) return 1; else return 0;
}
void kt1(long long n, long long a, long long b)
{
	float k;
	long flag=0;
    for (long long i=a;i<=b;i++)
    {
    	k=float(log(i))/log(n);
    	if(kt(k)==1) 
    	{
    		flag=1;
    		cout<<i<<" ";
		}
	}
	if(flag==0) cout<<"-1";
}
int main()
{
	long long l,r,x;
	cin>>l>>r>>x;
	kt1(x,l,r);
	return 0;
}
