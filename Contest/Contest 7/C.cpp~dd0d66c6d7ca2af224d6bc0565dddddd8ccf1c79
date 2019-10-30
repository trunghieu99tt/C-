#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define pb push_back

using namespace std;

set<string> ans;
vector<int> dr{-1,-1,-1,0,0,1,1,1},
    dc{-1,0,1,-1,1,-1,0,1};
int n;
char a[1000][1000];
map<pair<int,int>, int> visited;
string temp = "";
vector<string> possible;
map<string,int> checked;
int stop = 0, counter;
void solve(int r, int c)
{
    int flag = 0;
    for (int i = 0;i < 8;i++)
    {
        int x = r + dr[i], y = c + dc[i];
        if (x >= 0 && y >= 0 && x < n && y < n && visited[{x, y}] == 0)
        {
            int f = 0;
            temp += (a[x][y]);
            if(temp.back() == 'q')
            {
                f = 1;
                temp+='u';
            }
            visited[{x, y}] = 1;
            int flag = 0;
            string checker;
            for(auto j:possible)
            {
                if(temp == j)
                {
                    ans.insert(temp);
                    checked[temp] = 1;
                }
                else if(j.find(temp) == 0 && checked[j] == 0)
                    flag = 1;
            }
            if(flag)
                solve(x, y);
            temp.erase(temp.end() - 1);
            if(f)
                temp.erase(temp.end() - 1);
            visited[{x, y}] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int m,i;
    cin>>m;
    forn(i,m)
    {
        string t;
        cin>>t;
        possible.pb(t);
    }
    while(1)
    {
        cin>>n;
        if(n == 0)
            return 0;
        int i,j;
        forn(i,n)
            forn(j,n)
                cin>>a[i][j];
        ans.clear();
        checked.clear();
        forn(i,n)
            forn(j,n)
            {
                int flag = 0;
                for(auto k:possible)
                {
                    if(k.size() == 1 && k[0] == a[i][j] && k!="q")
                        ans.insert(k);
                    else if(k[0] == a[i][j])
                        flag=1;
                }
                if(flag)
                {
                    temp = "";
                    if(a[i][j] == 'q')
                        temp+="qu";
                    else temp+=a[i][j];
                    visited.clear();
                    visited[{i,j}] = 1;
                    solve(i,j);
                }
            }
        for(auto i:ans)
            cout<<i<<endl;
        cout<<"-\n";
    }
    return 0;
}