#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin>>n;
    int a[n],i,j;
    for(i = 0;i<n;i++)
        cin>>a[i];
    stack<int> prev, id;
    map<int,int> x;
    prev.push(a[n-1]);
    id.push(n-1);
    for(i = n - 2;i>=0;i--)
    {
        if(prev.empty())
        {
            prev.push(a[i]);
            id.push(i);
        }
        else
        {
            while(!prev.empty() && prev.top() < a[i])
            {
                x[id.top()] = i;
                prev.pop();
                id.pop();
            }
            prev.push(a[i]);
            id.push(i);
        }
    }
    while(!prev.empty())
    {
        x[id.top()] = -1;
        prev.pop();
        id.pop();
    }
    for(i = 0;i<n;i++)
        cout<<i - x[i]<<" ";
    return 0;
}