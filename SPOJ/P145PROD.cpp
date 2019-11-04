#include<iostream>
#include<iomanip>
#define pi 3.14159265358979
using namespace std;
int main()
{
		int r;
	cin>>r;
	cout<<setprecision(6)<<fixed<<r*r*pi<<endl;
	cout<<setprecision(6)<<fixed<<float(r*r*2);
	return 0;
}
