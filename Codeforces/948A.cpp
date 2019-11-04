#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int r,c;
    cin>>r>>c;
    char a[r][c];
    int i,j;
    forn(i,r)
        forn(j,c)
            cin>>a[i][j];
    forn(i,r)
        forn(j,c)
        {
            if(a[i][j] == '.')
                a[i][j] = 'D';
        }
    forn(i,r)
        forn(j,c)
        {
            if(a[i][j] == 'S')
            {
                if(i - 1 >=0 && a[i-1][j] == 'W'
                || j - 1>=0 && a[i][j-1] == 'W'
                || j + 1 < c && a[i][j+1] == 'W'
                || i + 1 < r && a[i+1][j] == 'W')
                {
                    cout<<"No";
                    return 0;
                }
                
            }
        }
    cout<<"Yes\n";
    forn(i,r)
    {
        forn(j,c)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}