#include<iostream>
#include<math.h>
#define maxn 10000
using namespace std;
int kt(float x)
{
	if(int(x)==x) return 1; else return 0;
}
int main()
{
	float n,m,i=0,x,y,min;
	cin>>n>>m;
	bool flag=false;
	min=maxn;
	while(pow(m,i)<n)
	 {
	 	x=n-pow(m,i);
	 	y=n-2*x;
	 	if(x>0 && y>0 && x+y<=min) min=x+y;
	 	i++;
	 }
	 cout<<min;
	 return 0;
}
