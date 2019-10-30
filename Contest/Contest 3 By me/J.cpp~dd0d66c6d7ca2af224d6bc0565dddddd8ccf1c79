#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    string a, b;
    cin>>a>>b;
    int n = a.size(),nA = (n%2 == 0)?(n/2):(n/2+1), nB = n - nA,i,idA = 0, idB = 0, turnA = 1, lo = 0, hi = n-1;
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    a = a.substr(0,nA); b = b.substr(0,nB);
    nA--;
    nB--;
    string ans(n,'?');
    while(lo <= hi)
    {
        if(turnA)
        {
            if(a[idA] > b[idB])
                ans[hi--] = a[nA--];
            else 
                ans[lo++] = a[idA++];
        }
        else
        {
            if(b[idB] > a[idA])
                ans[lo++] = b[idB++];
            else ans[hi--] = b[nB--];
        }
        turnA = !turnA;
    }
    cout<<ans;
    return 0;
}