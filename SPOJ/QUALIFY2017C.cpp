#include<iostream>
using namespace std;
int yeucau(int n)
{
	int kq,i;
	kq=n;
	for (i=1;i<n;i++)
	  if (n%i==0)kq-=i;
	return kq;
}
int main()
{
	int A,B,i,kq=0;
	cin>>A;
	cin>>B;
	for (i=A;i<=B;i++)
      kq+=yeucau(i);
    cout<<kq<<endl;
    return 0;
}
