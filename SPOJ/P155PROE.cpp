#include<iostream>
using namespace std;
int Return (int n)
{
	switch(n)
	{
		case 8:return 1;
		case 0:case 6:case 9:case 2: return 2;
		case 4:case 3:return 3;
		case 5: return 4;
		case 7: return 5;
		case 1: return 7;
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<Return(n%10)*Return(n/10);
	return 0;
} 
