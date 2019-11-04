#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,j,k=n/2,l=1,m;
	for (i=0;i<n/2;i++)
	{
		for (j=0;j<k;j++) cout<<"*";
			for (m=0;m<l;m++) cout<<"D";
				for (j=0;j<k;j++) cout<<"*";
		cout<<endl;
		k--;
		l+=2;
	}
	for (i=0;i<n;i++) cout<<"D";
		cout<<endl;
	k=1;
	l=n-2;
	for (i=0;i<n/2;i++)
	{
		for (j=0;j<k;j++) cout<<"*";
			for (m=0;m<l;m++) cout<<"D";
				for (j=0;j<k;j++) cout<<"*";
		cout<<endl;
	k++;
	l-=2;
	}
	return 0;
}