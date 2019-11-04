#include <iostream>
using namespace std;
int ok[20];
int main()
{
    long long p;
    cin>>p;
    long long i=1,s=9;
    int j,k;
    while (p>s*i)
    {
        p-=s*i;
        i++; s*=10;
    }
    s=s/9+p/i; p%=i;
    if (p==0)
    {
        p=i; s--;
    }
    i=0;
    while (s!=0)
    {
        j=s%10; s/=10;
        ok[i++]=j;
    }
    cout<<endl;
    cout<<ok[i-p];
    return 0;
}
