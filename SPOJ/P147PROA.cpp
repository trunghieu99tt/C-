#include<iostream>
#include<math.h>
using namespace std;
int main()
{
		int S,V,Q;
	float a,b,c; 
	cin>>S>>V>>Q;
	b=sqrt(float(Q*V)/S);
	a=b*(float(S)/V);
	c=float(V/b);
	cout<<4*(a+b+c);
		return 0;
}

