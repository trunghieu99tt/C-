#include<iostream>
#include<algorithm>
#include<iomanip>
#include<math.h>
using namespace std;
struct fPoint
{
	int x,y;
} ;
void Input(fPoint &A)
{
	cin>>A.x>>A.y;
}
double area(fPoint A, fPoint B, fPoint C)
{
	return abs(double((A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y)))/2.0);
}
bool isInside(fPoint A, fPoint B, fPoint C, fPoint P)
{
	return((area(A,B,P)+area(A,C,P)+area(B,C,P))==area(A,B,C));
}
int main()
{
	cout<<setprecision(1)<<fixed;
	fPoint A,B,C;
	Input(A);
	Input(B);
	Input(C);
	int n,i,counter=0;
	cin>>n;
	fPoint D;
	for (i=0;i<n;i++)
	{
		Input(D);
		if(isInside(A,B,C,D)==true) counter++;
	}
	cout<<area(A,B,C)<<endl;
	cout<<counter;
	return 0;
} 
