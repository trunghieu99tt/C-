#include<iostream>
using namespace std;
int Sodacbiet(int n)
{
	int i,flag=1;
	for (i=2;i<n/2;i++)
		if(n%(i*i)==0) flag=0;
	if(flag==1) return 1; else return 0;
}
int main()
{
	int n,i,max,flag=0;
	cin>>n;
	for (i=n;i>0;i--)
	  if((n%i==0)&&(Sodacbiet(i)==1))
	  {
	  	max=i;
	  	flag=1;
	  	break;
	  }
	if(flag==1) cout<<max<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
