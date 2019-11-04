#include<iostream>
using namespace std;
int main()
{
	long long ax,ay,bx,by,cx,cy;
	cin>>ax>>ay;
	cin>>bx>>by;
	cin>>cx>>cy;
	long long k=(bx-ax)*(cy-ay)-(cx-ax)*(by-ay);
	if(k==0) cout<<"TOWARDS";
	else if(k>0) cout<<"LEFT";
	else cout<<"RIGHT";
	return 0;
}
