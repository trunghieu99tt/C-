#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout<<setprecision(2)<<fixed;
	int testcase=1;
	while(1)
	{
		int n;
		cin>>n;
		if(n<0) return 0;
		long long xi,yi,mi,sum_m_i=0,product_m_y=0,product_m_x=0;
		int i;
		for (i=0;i<n;i++)
		{
			cin>>xi>>yi>>mi;
			sum_m_i+=mi;
			product_m_x+=(mi*yi);
			product_m_y+=(mi*xi);
		}
		double resultx=double(product_m_x)/sum_m_i,resulty=double(product_m_y)/sum_m_i;
		cout<<"Case "<<testcase++<<": "<<resulty<<" "<<resultx<<endl;
	}
} 
