#include<iostream>
using namespace std;
int main()
{
	long n,kq=0;
	cin>>n;
	string s;
	for (long i=0;i<n;i++)
	{
		cin>>s;
		if(s=="++X") ++kq;
		else if(s=="X++")kq++;
		else if(s=="X--") kq--;
		else if(s=="--X")--kq;
	}
	cout<<kq;
}
