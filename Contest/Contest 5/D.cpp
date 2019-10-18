#include<bits/stdc++.h>

using namespace std;

#define maxn 10000

int snt[maxn+1], i,j;

string toStr(int n)
{
    ostringstream s;
    s<<n;
    return s.str();
}
void sangnt()
{
    for(i = 1;i<=maxn;i++)
        snt[i] = 1;
    snt[1] = 0;
    i = 2;
    while(i*i<=maxn)
    {
        while(snt[i]==0)
            i++;
        for(j = 2;j*i<=maxn;j++)
            snt[i*j] = 0;
        i++;
    }
}

void trunghieu()
{
    sangnt();
    int t,k;
    cin>>t;
    for(k = 0;k<t;k++)
    {
        int begin,end;
        cin>>begin>>end;
        vector<int> level(maxn+1,-1);
        queue<int> q;
        level[begin] = 0;
        q.push(begin);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            string s = toStr(u);
            for(i = 0;i<4;i++)
            {
                for(j = 0;j<=9;j++)
                {
                    string temp = s;
                    temp[i] = j + '0';
                    int num = atoi(temp.c_str());
                    if(num>=1000 && snt[num] && level[num] == - 1)
                    {
                        level[num] = level[u] + 1;
                        q.push(num);
                    }
                }
            }
        }
        cout<<level[end]<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    trunghieu();
}