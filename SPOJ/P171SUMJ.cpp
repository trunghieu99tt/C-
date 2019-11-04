#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
		long long a,b,c;
	cin>>a>>b>>c;
	if(a==0)
	{
		if(b==0)
		{
			if(c!=0) cout<<"NO";
        }
		else 
		{
			cout<<setprecision(2)<<fixed<<-1.0*(double)c/(double)b;
		}
	}
	else
	{
		long long delta;
		delta=b*b-4*a*c;
		if(delta<0) cout<<"NO";
		else if(delta==0) 
		{
			cout<<setprecision(2)<<fixed<<-1.0*double(b)/(2.0*(double)a);
		}
		else 
		{
			cout<<setprecision(2)<<fixed;
			double x1=double(-1.0*(double)b+(double)sqrt(delta))/(2.0*(double)a),x2=double(-1.0*(double)b-(double)sqrt(delta))/(2.0*(double)a);
			cout<<x1<<" "<<x2;
		}
	}
	return 0;
}
