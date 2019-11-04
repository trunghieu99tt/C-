#include<iostream>
using namespace std;
void UCLN(long long a, long long b)
{
	long UCLN,BCNN,tama,tamb;
	tama=a; tamb=b;
	while (b!=0) {
        long long x = a%b;
        a = b;
        b = x;
    }
    UCLN=a;
	BCNN=(tama*tamb)/UCLN;
	cout<<UCLN<<" "<<BCNN<<endl;
}
int main()
{
	long long a,b;
	cin>>a>>b;
		UCLN(a,b);
	return 0;
}
