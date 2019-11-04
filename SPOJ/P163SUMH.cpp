#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int a,b,dem=0,dem1=0,dem2=0;
	cin>>a; cin>>b;
	for (int i=1;i<=6;i++)
	{
		if(abs(i-a)<abs(i-b)) dem++;
		else if(abs(i-a)==abs(i-b))dem1++;
		else dem2++;
	}
	cout<<dem<<" "<<dem1<<" "<<dem2;
}
