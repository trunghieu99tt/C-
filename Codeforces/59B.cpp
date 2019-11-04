#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    long n,i,vitri;
    cin>>n;
    long a[n],max;
    vector <long> b;
    bool flag=false;
    for (i=0;i<n;i++) 
    {
        cin>>a[i];
        if(a[i]%2!=0) 
            flag=true;
        b.push_back(a[i]);
    }
    if(flag==true) 
    {
        long kq=0;
        sort(b.begin(),b.end());
        for (i=b.size()-1;i>=0;i--)
            kq+=b[i];
        if(kq%2==0) 
        {
            for (i=0;i<b.size();i++) if((kq-b[i])%2!=0)
            {
                cout<<kq-b[i];
                break;
            }
        }
        else cout<<kq;
    }
    else cout<<0;
    return 0;
}
 