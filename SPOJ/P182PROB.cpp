#include<iostream>
#include <algorithm>
using namespace std;
long long Combination(int k, int n)
{
    long long r=1;
    for (int i=1;i<=k;i++,n--)
        r=r*n/i;
    return r;
}
int main()
{
    int n;
    cin>>n;
    long a[n],i;
    for (i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
    // Trường hợp nếu 3 số= nhau
    if(a[0]==a[1] && a[1]==a[2]) 
        {
            i=0;
            int dem=0;
            for (i=0;i<n;i++)
                {
                    if(a[i]==a[0]) dem++;
                    else if(a[i]>a[2]) break;
                }
            cout<<Combination(3,dem);
        }
    else if(a[0]==a[1] && a[1]!=a[2] || (a[0]!=a[1]) && a[1]==a[2]) 
    {
        // Trường hợp a0=a1,a1!=a2
        if(a[0]==a[1] && a[1]!=a[2])
        {
            int dem1=0,dem2=0;
            for (i=0;i<n;i++) 
            {
                if(a[i]==a[0]) dem1++;
                else if(a[i]==a[2]) dem2++;
                else if(a[i]>a[2]) break;
            }
            cout<<Combination(2,dem1)*Combination(1,dem2);
        }
        //Trường hợp a0!=a1,a1=a2
        else if((a[0]!=a[1]) && a[1]==a[2])
        {
            int dem1=0,dem2=0;
            for (i=0;i<n;i++) 
            {
                if(a[i]==a[0]) dem1++;
                else if(a[i]==a[2]) dem2++;
                else if(a[i]>a[2]) break;
            }
            cout<<Combination(1,dem1)*Combination(2,dem2);
        }
    }
    else if(a[0]!=a[1] && a[1]!=a[2] && a[2]!=a[0])
    {
        // Trường hợp 3 số khác nhau
        int dem1=0,dem2=0,dem3=0;
        for (i=0;i<n;i++)
        {
            if(a[i]==a[0]) dem1++;
            else if(a[i]==a[1]) dem2++;
            else if(a[i]==a[2]) dem3++;
            else if(a[i]>a[2]) break;
        }
        cout<<Combination(1,dem1)*Combination(1,dem2)*Combination(1,dem3);
    }
    return 0;
}