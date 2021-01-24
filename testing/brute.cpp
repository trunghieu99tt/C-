#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int C[101][101];
    while(N--)
    {
        int a,b;
        cin>>a>>b;
        int token;
        memset(C,0,sizeof(C));
        for (int i=1; i<=a; i++)
        {
            for (int j=1; j<=b; j++)
            {
                cin>>token;
                C[0][j]+=token;
                C[i][0]+=token;
            }
        }
        int c;
        for (int i=1; i<=a; i++)
        {
            for (int j=1; j<=b; j++)
            {
                c=min(1,C[0][j]+C[i][0]);
                cout<<c<<' ';
            }
            cout<<endl;
        }
    }
}